#include<stdio.h>
#include <stdlib.h> 

int main()
{
    char c[1000];
    FILE *fptr;

    if ((fptr = fopen("file1.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // exit from program if file pointer returns NULL.
        exit(1);         
    }
    // read text until newline 
    fscanf(fptr,"%[^\n]", c);
    printf("Data from the file:\n%s", c);
    fclose(fptr);
    
    return 0;
}