#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIMREAD 5

typedef struct
{
    pthread_mutex_t *mut, *readMut;
    int writers;
    int readers;
    int waitingWriter;
    int waitingReader;
    int finishedReading;
    int finishedWriting;
    pthread_cond_t *writeOK, *readOK, *allRead;
} rwl;

rwl *initlock(void);              // initializing lock in which mutex and cond is initialized and default value is given to no of readers,writers, waitingWriter
void readlock(rwl *lock, int d);  //  locking the reader
void writelock(rwl *lock, int d); //  locking the writer
void readunlock(rwl *lock);       //  unlocking the reader
void writeunlock(rwl *lock);      //  unlocking the writer
void deletelock(rwl *lock);       //  destroying the mutex and cond condition variable

typedef struct
{
    rwl *lock;  // pointer to struct of lock
    int id;     // id for reader or writer
    long delay; // setting how much time to delay for particular id
} rwargs;

rwargs *newRWargs(rwl *l, int i, long d); // allocating memory for struct
void *reader(void *args);                 // function to tell reader to do task in parellel
void *writer(void *args);                 // function to tell writer to do task in parellel
static int data = 1;

int main()
{
    pthread_t th_arr[15]; // initializing array for thread
    rwargs *rw[15];       // making array of struct rwargs
    rwl *lock;            // making pointer of struct rwl
    lock = initlock();    // allocating memory to lock pointer

    for (int i = 0; i < 15; i++)
    {
        if (i < 5)
        {
            rw[i] = newRWargs(lock, i + 1, 200000);
            if (pthread_create(&th_arr[i], NULL, &writer, rw[i]) != 0)
            {
                perror("ERROR IN CREATING THREADS\n");
                return 0;
            }
        }
        else
        {
            rw[i] = newRWargs(lock, i - 4, 50000);
            if (pthread_create(&th_arr[i], NULL, &reader, rw[i]) != 0)
            {
                perror("ERROR IN CREATING TRHEADS\n");
                return 0;
            }
        }
    }
    for (int i = 0; i < 15; i++)
    {
        if (pthread_join(th_arr[i], NULL) != 0)
        {
            return 0;
        }
    }
    deletelock(lock);

    return 0;
}
rwargs *newRWargs(rwl *l, int i, long d)
{
    rwargs *args;                            // initializing pointer to rwargs
    args = (rwargs *)malloc(sizeof(rwargs)); // allocating memory
    if (args == NULL)                        // if error in allocation return null
    {
        return (NULL);
    }

    // adding values to struct created through passed parameters
    args->lock = l;
    args->id = i;
    args->delay = d;

    return (args); // returning the pointer to struct
}
void *reader(void *args)
{
    rwargs *a; // initializing pointer to rwargs
    int d;
    a = (rwargs *)args; // typecasting void* to rwags* and storing in "a"
    do
    {
        readlock(a->lock, a->id);                                    // trying to lock mutex so reader can read the written value by writer
        d = data;                                                    // after locking adding data to variable d so tu run loop until it is finished that is d=0
        usleep(a->delay);                                            // delaying the reader so that other thread can continue in parellel if any is waitingWriter for mutex to unlock
        readunlock(a->lock);                                         // unlocking the mutex
        printf("READER_NUMBER {%d} : READ_DATA = {%d}\n", a->id, d); // printing accesed value
        usleep(a->delay);                                            // again delay
        if (data == 0)
        {
            break;
        }
        // printf("OnceReadNowWaiting : {%d}\n", a->id);
        pthread_mutex_lock(a->lock->readMut);

        if (a->lock->finishedReading % 10 == 0)
        {
            pthread_cond_signal(a->lock->writeOK);
            usleep(100000);
            pthread_cond_broadcast(a->lock->allRead);
        }
        while (a->lock->finishedReading % 10 != 0)
        {
            pthread_cond_wait(a->lock->allRead, a->lock->readMut);
        }
        pthread_mutex_unlock(a->lock->readMut);
    } while (d != 0);                                 // will run for atleast once and run till d1=0
    printf("READER_NUMBER {%d}: FINISHED.\n", a->id); // once every reader has completed print it
    return (NULL);                                    // return null to stop and proceed to join
}

void *writer(void *args)
{
    rwargs *a;                                                   // initializing pointer to rwargs
    a = (rwargs *)args;                                          // typecasting void* to rwags* and storing in "a"
    writelock(a->lock, a->id);                                   // trying to lock mutex so writer can write value
    data++;                                                      // writing to data variable
    usleep(a->delay);                                            // delay for 1.5 seconds
    writeunlock(a->lock);                                        // unlocking mutex
    printf("WRITER_NUMBER {%d}: WROTE_DATA{%d}\n", a->id, data); // flushing the value to stdout what is written by writer
    usleep(a->delay);                                            // again delaying so other thread can continue
    printf("WRITER_NUMBER {%d}: FINISHING....\n", a->id);        // once finished writing for 4 times print this
    writelock(a->lock, a->id);                                   // again lock for finally setting value of data =0
    a->lock->finishedWriting++;
    if (a->lock->finishedWriting == 5)
    {
        data = 0;
    }
    writeunlock(a->lock);
    printf("WRITER_NUMBER {%d} : FINISHED.\n", a->id); // finished completly

    return (NULL); // returning null to stop and proceed to join thread
}
rwl *initlock(void)
{
    rwl *lock;
    lock = (rwl *)malloc(sizeof(rwl)); // allocating memory
    if (lock == NULL)                  // if any error in allocating -> return
        return (NULL);
    lock->mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (lock->mut == NULL) // if any error in allocating -> return
    {
        free(lock);
        return (NULL);
    }
    lock->readMut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (lock->readMut == NULL) // if any error in allocating -> return
    {
        free(lock);
        return (NULL);
    }
    lock->writeOK =
        (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    if (lock->writeOK == NULL) // if any error in allocating -> return
    {
        free(lock->mut);
        free(lock);
        return (NULL);
    }
    lock->readOK =
        (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    lock->allRead =
        (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    if (lock->readOK == NULL) // if any error in allocating -> return
    {
        free(lock->mut);
        free(lock->writeOK);
        free(lock);
        return (NULL);
    }
    pthread_mutex_init(lock->mut, NULL);     // initializing mutex
    pthread_mutex_init(lock->readMut, NULL); // initializing mutex
    pthread_cond_init(lock->writeOK, NULL);  // intializing cond(writeOk)
    pthread_cond_init(lock->readOK, NULL);   // intializing cond(readOk)
    pthread_cond_init(lock->allRead, NULL);  // intializing cond(readOk)
    lock->readers = 0;
    lock->writers = 0;
    lock->waitingWriter = 0;
    lock->waitingReader = 0;
    lock->finishedReading = 0;
    lock->finishedWriting = 0;
    return (lock);
}
void readlock(rwl *lock, int d)
{
    pthread_mutex_lock(lock->mut); // firstly lock mutex for to give access to a resource to only one process at a time
    lock->waitingReader++;
    if (lock->writers || lock->waitingWriter)
    {
        do
        {
            printf("\nREADER_NUMBER{%d} --> BLOCKED.\n", d);    // lock the reader
            pthread_cond_wait(lock->readOK, lock->mut);         // wait for writer signal to complete its task first
            printf("\nREADER_NUMBER {%d} --> UNBLOCKED.\n", d); // when signal from writer has come then unblock reader and continue
        } while (lock->writers);                                // while writer hasn't done its work
    }
    lock->waitingReader--;
    lock->readers++;
    // printf("\nWRITER_NUMBER : {%d} NUMBER_OF_WAITINGWRITER : {%d} READER_NUMBER : {%d} NUMBER_OF_WAITINGREADERS : {%d} NUMBER_OF_FINISHEDREADER : {%d} NUMBER_OF_FINISHEDWRITING : {%d}\n", lock->writers, lock->waitingWriter, lock->readers, lock->waitingReader, lock->finishedReading % 10, lock->finishedWriting);
    pthread_mutex_unlock(lock->mut); // unlock the mutex
    return;
}
void writelock(rwl *lock, int d)
{
    pthread_mutex_lock(lock->mut);         // firstly lock mutex for to give access to a resource to only one process at a time
    lock->waitingWriter++;                 // increase count of waitingWriter thread
    while (lock->readers || lock->writers) // run loop if any reader is waitingWriter or any writer is waitingWriter
    {
        printf("\nWRITER_NUMBER {%d} --> BLOCKED.\n", d);
        pthread_cond_wait(lock->writeOK, lock->mut);
        printf("\nWRITER_NUMBER {%d} --> UNBLOCKED.\n", d);
    }
    lock->waitingWriter--;
    lock->writers++;
    // printf("\nWRITER_NUMBER : {%d} NUMBER_OF_WAITINGWRITER : {%d} READER_NUMBER : {%d} NUMBER_OF_WAITINGREADERS : {%d} NUMBER_OF_FINISHEDREADER : {%d} NUMBER_OF_FINISHEDWRITING : {%d}\n", lock->writers, lock->waitingWriter, lock->readers, lock->waitingReader, lock->finishedReading % 10, lock->finishedWriting);

    pthread_mutex_unlock(lock->mut);
    return;
}
void readunlock(rwl *lock)
{
    pthread_mutex_lock(lock->mut);
    lock->readers--;
    lock->finishedReading++;
    if (lock->finishedReading % 10 == SIMREAD)
    {
        pthread_cond_signal(lock->writeOK);
    }
    else if (lock->finishedWriting != 5)
    {
        pthread_cond_signal(lock->readOK);
    }

    pthread_mutex_unlock(lock->mut);
}

void writeunlock(rwl *lock)
{
    pthread_mutex_lock(lock->mut);
    lock->writers--;
    if (lock->waitingReader)
        pthread_cond_signal(lock->readOK);
    else if (lock->finishedWriting != 5)
    {
        pthread_cond_signal(lock->writeOK);
    }
    pthread_mutex_unlock(lock->mut);
}
void deletelock(rwl *lock)
{
    pthread_mutex_destroy(lock->mut);
    pthread_mutex_destroy(lock->readMut);
    pthread_cond_destroy(lock->readOK);
    pthread_cond_destroy(lock->writeOK);
    pthread_cond_destroy(lock->allRead);
    free(lock);
    return;
}