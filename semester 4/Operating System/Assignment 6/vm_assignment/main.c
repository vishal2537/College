/*
Main program for the virtual memory project.
Make all of your modifications to this file.
You may add or rearrange any code or data as you need.
The header files page_table.h and disk.h explain
how to use the page table and disk interfaces.
*/

#include "program.h"
#include "page_table.h"
#include "disk.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



// Global Variables
int nframes; // stores total number of frames
int *is_frame_occup_struc = NULL; // pointer to free frame data structure
int *frame_holds_what = NULL;		// array to maintain which frame holds which physical page
char *usedAlgo;				// store which page replacement algorithm to use 

char *virtmem = NULL;
char *physmem = NULL;
struct disk *disk = NULL; // global pointer to disk



// data struct for fifo
int oldest_page = 0;
int newest_page = 0;
int *fifo_page_queue = NULL;



// data struct for LRU
struct page_node
{
	int page;
	struct page_node *nextPage;
}*head, *tail, *currPage, *newPage, *prevPage;



// Variables used to track statistics to print at the end
int pageFaults = 0;
int diskReads = 0;
int diskWrites = 0;



// function definitions
int findnset_free_frame(int *is_frame_occup_struc,int nframes);
void random_pra( struct page_table *pt, int page );
void fifo_pra( struct page_table *pt, int page);
void custom_pra( struct page_table *pt, int page);
void replace_page( struct page_table *pt, int page, int frame_no_toremove );
void rearrange_page_list(int i);
static int compare_bytes( const void *pa, const void *pb );


/* This function handles the page faults generated while accessing the memory

	In this version the entry is first given only the read access and then is required write access is given
*/
void page_fault_handler( struct page_table *pt, int page )
{
//    printf("page fault on page #%d\n",page); // print this virtual page is needed

	pageFaults++;							//increment page faults

	// variables to store information about the page on which page fault has occured
    int curr_bits;
    int curr_frame;
    
	// get the details of the page table entry corresponding to the page i.e. which frame does it hold and what are the permission bits
    page_table_get_entry( pt, page, &curr_frame, &curr_bits ); 
       

    // FAULT TYPE 1 - page not in virtual memory i.e. no protection bits set i.e. entry in page table is free 
    if ( ( (curr_bits & PROT_READ)==0 ) && ( (curr_bits & PROT_WRITE)==0 ) && ( (curr_bits & PROT_EXEC)==0 ) )
    {
		// find a free frame
		int free_loc = findnset_free_frame(is_frame_occup_struc, nframes);

		if (free_loc != -1) // have found a free frame. Bring page in that free frame
		{
			// set an entry of page in page table to free_loc frame location and give read access to it
			page_table_set_entry(pt, page, free_loc, 0|PROT_READ);

			// if fifo then need to store this frame in queue 
			if ( !strcmp(usedAlgo, "fifo") )
			{
				fifo_page_queue[newest_page] = free_loc;
				newest_page = (newest_page + 1) % nframes;		// make it a circular queue
			}

			// if LRU then create a new node for this page in page list
			if ( !strcmp(usedAlgo, "custom") )
			{
				newPage = (struct page_node *) malloc(sizeof(struct page_node));
				newPage->page = page;
				newPage->nextPage = NULL;
	
				if (head == NULL)
				{
					head = newPage;
					tail = head;
				}
				else
				{
					tail->nextPage = newPage;
					tail = newPage;
				}
			}
	
			// Read data from disk at virtual address given by 'page' to physical memory frame
			disk_read(disk, page, &physmem[free_loc*PAGE_SIZE]);
			diskReads++;

			// Store info that this page is held in which page frame.
			// this frame holds this page, inverse of page table.
			frame_holds_what[free_loc] = page; 
		}

		else		// all frames all full. Need to kick out some page from some frame. Will need page replacement algorithm. Call the page replacement algorithm given by the user.
		{ 
			if (!strcmp(usedAlgo, "rand"))
			{
				random_pra(pt, page);
			}

			else if (!strcmp(usedAlgo, "fifo"))
			{
				fifo_pra(pt, page);
			}
			
			else if (!strcmp(usedAlgo, "custom"))
			{
				custom_pra(pt, page);
			}

			else //check for incorrect policy name
			{
				printf("use: virtmem <npages> <nframes> <rand|fifo|custom> <sort|scan|focus>\n");
				exit(1);
			}			
		}
    }

    else // FAULT TYPE 2 - page is in virtual memory but does not have necessary permissions
    {
		// dont have write permission but has read
		if ( ( (curr_bits & PROT_WRITE)==0 ) && ( ( curr_bits & PROT_READ ) ==1 ) )
		{
			//OR curr_bits with PROC masks to get 1's at req positions.		   
			page_table_set_entry( pt, page, curr_frame, curr_bits | PROT_WRITE);  
		}

		else // has write but not read, may happen though unlikely
		{
			// OR with write permission
			page_table_set_entry( pt, page, curr_frame, curr_bits | PROT_READ);
		}
    }

// For testing purpose
//	page_table_print(pt);

} 



int main( int argc, char *argv[] )
{
	// check if all command line arguments are given
	if(argc!=5) {
		printf("use: virtmem <npages> <nframes> <rand|fifo|custom> <sort|scan|focus>\n");
		return 1;
	}

	// derive details of the program to run from command line arguments
	int npages = atoi(argv[1]);
	nframes = atoi(argv[2]);		//made global
	usedAlgo = argv[3];			// store which page replacement algorithm to use 
	const char *program = argv[4];	// store which testing program to run

	
	is_frame_occup_struc = malloc(nframes * sizeof(int)); // allocate memory for structure storing frame occupation info

	if(is_frame_occup_struc == NULL) {
		printf("Error allocating space for structure storing frame occupation information!\n");
		exit(1);
	}

	frame_holds_what = malloc(nframes * sizeof(int));		// allocate memory for array storing which frame holds which physical page
    
	if(frame_holds_what == NULL) {
		printf("Error allocating space for array storing info about which frame holds what page!\n");
		exit(1);
	}


    // initialize the arrays to store frame status
    for(int i=0; i < nframes; i++)
    {
       is_frame_occup_struc[i] = 0;  // initially no frame is occupied
       frame_holds_what[i] = 0;  		// initially no frame holds any physical page
    }


	// for fifo
	if ( !strcmp(usedAlgo, "fifo") )
	{
		fifo_page_queue = malloc(nframes * sizeof(int));		// allocate memory for fifo queue
		if(fifo_page_queue == NULL) {
			printf("Error allocating space for fifo page queue!\n");
			exit(1);
		}
	}

	// for LRU, initialize pointers to page list
	if ( !strcmp(usedAlgo, "custom") )
	{
		head = NULL;
		tail = NULL;
		currPage = head;
	}

	// try to create a disk
	disk = disk_open("myvirtualdisk", npages);
	
	// if 0 is returned then disk is not created. Therefore show error
	if(!disk) {
		fprintf(stderr,"couldn't create virtual disk: %s\n",strerror(errno));
		return 1;
	}

	// try to cretae page table
	struct page_table *pt = page_table_create( npages, nframes, page_fault_handler );
	
	// if 0 is returned then page table is not created. Therefore show error
	if(!pt) {
		fprintf(stderr,"couldn't create page table: %s\n",strerror(errno));
		return 1;
	}

	// get pointer to virtual memory from the page table
	virtmem = page_table_get_virtmem(pt);

	// get pointer to physical memory from the page table
	physmem = page_table_get_physmem(pt);


	// run appropriate program base on the command given by the user.
	if(!strcmp(program,"sort")) {
		sort_program(virtmem,npages*PAGE_SIZE);

	} else if(!strcmp(program,"scan")) {
		scan_program(virtmem,npages*PAGE_SIZE);

	} else if(!strcmp(program,"focus")) {	 
		focus_program(virtmem,npages*PAGE_SIZE);

	} else {
		fprintf(stderr,"unknown program: %s\n",argv[3]);

	}


	//printing final state of the page table
	printf("--------------------------------------------------------------\n");
	printf("Final Page Table\n");
	page_table_print(pt);
	printf("--------------------------------------------------------------\n");


	//print results to user
	printf("Disk Reads: %d\n", diskReads);
	printf("Disk Writes: %d\n", diskWrites);
	printf("Page Faults: %d\n", pageFaults);


	// free the allocated resources
	free(is_frame_occup_struc);
    free(frame_holds_what);

	// clean used resources
	page_table_delete(pt);
	disk_close(disk);

	return 0;
}



/*
	This function implements random page replacement algorithm when a page fault occurs
	Algorithm: A random frame is chosen from available frames for replacement and the page that it holds is replaced
*/
void random_pra( struct page_table *pt, int page )
{
	int frame_no_toremove= (int)lrand48()%nframes;		// select a random frame to remove

	replace_page(pt, page, frame_no_toremove);
}



/*
	This function implements first in first out (fifo) page replacement algorithm when a page fault occurs
	Algorithm: A page which came first is chosen for replacement.
*/ 
void fifo_pra( struct page_table *pt, int page )
{
	int frame_no_toremove= fifo_page_queue[oldest_page];	// select first frame in the queue to replace

	// NOTE here that page will be replaced only if all frames are full
	// i.e. pointer to newest page location point actually at oldest page which is to be deleted	

	// shift oldest_page to next oldest_page so that this page is removed from the queue
	oldest_page = (oldest_page + 1) % nframes;
	
	replace_page(pt, page, frame_no_toremove);

	// add the new page at the back of the queue and shift newest_page pointer so that it again points at the location of oldest page which is to be replaced next time.
	fifo_page_queue[newest_page] = frame_no_toremove;
	newest_page = (newest_page + 1) % nframes;		// make it a circular queue
}


/*
	This function implements Least Recently Used (LRU) page replacement algorithm when a page fault occurs
	Algorithm: Here Linked List approach is used for implementing LRU. 
		1. If a new page arrives and if there is space in page table, then a new entry is made for that page at the end of the linked list. 
		2. If a page which is in linked list is referenced again, thenit is put at the end of the list.
		3. If a new page is arrived and an old page is to be replaced, then the page at the front of the list is replaced and the new page 				is put at the back of the list.
*/ 
void custom_pra( struct page_table *pt, int page )
{
	int frame_no_toremove = head->page;			// select first page in the page list (which is least recenly used) for replacement.

	// NOTE here that page will be replaced only if all entries in page table are full
	
	// shift oldest_page to next oldest_page so that this page is removed from the queue
	currPage = head;
	head = head->nextPage;
	tail->nextPage = currPage;
	tail = currPage;
	currPage->nextPage = NULL;
	
	replace_page(pt, page, frame_no_toremove);
}



/* This function replaces the given page (according to page replacement policy) with the new page */
void replace_page( struct page_table *pt, int page, int frame_no_toremove )
{
	int pageno_to_remove= frame_holds_what[frame_no_toremove]; // what page does the frame hold?

	// get page table entry of that page
	int frame_toremove; 
	int frame_toremove_bits;

	page_table_get_entry(pt, pageno_to_remove, &frame_toremove, &frame_toremove_bits ); // info from page table 


	// if dirty i.e if it has write access, then have to write this page back in disk and then replace the page
	if ( (frame_toremove_bits&PROT_WRITE)!=0 )
	{
		disk_write( disk,pageno_to_remove, &physmem[(frame_toremove)*PAGE_SIZE] ); // write back page to disk
		diskWrites++;	
	}

	page_table_set_entry( pt, pageno_to_remove, 0, 0); // 0's invalidate frame entry of previous page

	page_table_set_entry( pt, page, (frame_toremove), 0|PROT_READ ); // set new page table entry with read permission

	disk_read( disk, page, &physmem[(frame_toremove)*PAGE_SIZE] ); // Read data from disk at virtual address given by 'page' to physical memory frame
	diskReads++;


	// Store info that this page is held in which age frame.
	// this frame holds this page, inverse of page table.
	frame_holds_what[(frame_toremove)] = page; // the frame now contains this page.
}



/*
	This function tries to find a free frame from the available frames

	INPUT: Structure storing the occupation information of all frames, total frames
	OUTPUT: Position of free frame if a free frame is found. Otherwise -1.
*/
int findnset_free_frame(int *is_frame_occup_struc, int nframes)
{
    int i;
    
	for (i=0;i<nframes;i++)
	{
		if (is_frame_occup_struc[i] == 0) 	// if a free frame is found
		{
			is_frame_occup_struc[i] = 1; // mark that frame as occupied for the new incoming page 
			return i;					// return the position of frame
		}
	}

	// if no free frame is found, the whole page table is full, return -1
	return -1;
}

/* This function compares bytes and returns which one is greater 
*/
static int compare_bytes( const void *pa, const void *pb )
{
	int a = *(char*)pa;
	int b = *(char*)pb;

	if(a<b) {
		return -1;
	} else if(a==b) {
		return 0;
	} else {
		return 1;
	}

}


/* This function re-arranges the page list by removing existing page from the list and putting it at the tail of the list.
	This is a requirement for LRU page Replacement algorithm 
*/
void rearrange_page_list(int i)
{
	int page_accessed = i/PAGE_SIZE;

	//check if page in list. If page not found then there is already a fault which will be handled
	// if page found the put it at tail i.e. most recently used

	prevPage = NULL;
	currPage = head;

	while ( currPage != NULL )
	{
	
		if (currPage->page == page_accessed)
		{
			// remove page and put and tail
		
			if (currPage != tail)
			{
				if(currPage != head)
				{
					prevPage->nextPage = currPage->nextPage;				
					currPage->nextPage = tail->nextPage;
					tail->nextPage = currPage;
					tail = currPage;
				}
				else
				{
					head = head->nextPage;
					tail->nextPage = currPage;
					currPage->nextPage = NULL;
				}
			}

			break;
		}

		prevPage = currPage;
		currPage = currPage->nextPage;
	}
}
