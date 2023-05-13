#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIMREAD 5

typedef struct
{
    pthread_mutex_t *mut, *readMut; // initializing mutex to give access to a resource to only one process at a time
    int writers;                    // defining number of writers
    int readers;                    // defining number of readers
    int waitingWriter;              // defining number of threads waitingWriter
    int waitingReader;
    int finishedReading;
    int finishedWriting;
    pthread_cond_t *writeOK, *readOK, *allRead; /* it is condition variable
     this is used to send signals in between threads so to work synchronously */
} rwl;

rwl *initlock(void);              // initializing lock in which mutex and cond is initialized and default value is given to no of readers,writers, waitingWriter
void readlock(rwl *lock, int d);  // function for locking the reader
void writelock(rwl *lock, int d); // function for locking the writer
void readunlock(rwl *lock);       // function for unlocking the reader
void writeunlock(rwl *lock);      // funciton for unlocking the writer
void deletelock(rwl *lock);       // function for destroying the mutex and cond condition variable

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
    pthread_t threadArray[15]; // initializing array for thread
    rwargs *rw[15];            // making array of struct rwargs
    rwl *lock;                 // making pointer of struct rwl
    lock = initlock();         // allocating memory to lock pointer

    for (int i = 0; i < 15; i++)
    {
        if (i < 5)
        {
            rw[i] = newRWargs(lock, i + 1, 250000);
            if (pthread_create(&threadArray[i], NULL, &writer, rw[i]) != 0)
            {
                perror("Error in creating thread\n");
                return 0;
            }
        }
        else
        {
            rw[i] = newRWargs(lock, i - 4, 40000);
            if (pthread_create(&threadArray[i], NULL, &reader, rw[i]) != 0)
            {
                perror("Error in creating thread\n");
                return 0;
            }
        }
    }
    for (int i = 0; i < 15; i++)
    {
        if (pthread_join(threadArray[i], NULL) != 0)
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
        return (NULL);
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
        readlock(a->lock, a->id); // trying to lock mutex so reader can read the written value by writer
        d = data;                 // after locking adding data to variconcept that is frequeable d so tu run loop until it is finished that is d=0
        usleep(a->delay);         // delaying the reader so that other thread can continue in parellel if any is waitingWriter for mutex to unlock
        readunlock(a->lock);      // unlocking the mutex
        if (a->lock->finishedWriting < 5)
            printf("Reader %d : Data = %d\n", a->id, d); // printing accesed value
        usleep(a->delay);                                // again delay
        if (data == 0 || a->lock->finishedWriting == 5)
        {
            data = 0;
            pthread_cond_broadcast(a->lock->allRead);
            pthread_cond_broadcast(a->lock->readOK);
            break;
        }
        pthread_mutex_lock(a->lock->readMut);
        if (a->lock->finishedReading % SIMREAD == 0)
        {
            pthread_cond_signal(a->lock->writeOK);
            usleep(200000);
            pthread_cond_broadcast(a->lock->allRead);
        }
        while (a->lock->finishedReading % SIMREAD != 0 && data != 0)
        {
            pthread_cond_wait(a->lock->allRead, a->lock->readMut);
        }
        pthread_mutex_unlock(a->lock->readMut);
    } while (d != 0);                        // will run for atleast once and run till d1=0
    printf("Reader %d: Finished.\n", a->id); // once every reader has completed print it
    return (NULL);                           // return null to stop and proceed to join
}
void *writer(void *args)
{
    rwargs *a;                 // initializing pointer to rwargs
    a = (rwargs *)args;        // typecasting void* to rwags* and storing in "a"
    writelock(a->lock, a->id); // trying to lock mutex so writer can write value
    data++;                    // writing to data variable
    usleep(a->delay);          // delay for 1.5 seconds
    writeunlock(a->lock);
    printf("Writer %d: Wrote %d\n", a->id, data); // flushing the value to stdout what is written by writer
    usleep(a->delay);                             // again delaying so other thread can continue
    printf("Writer %d: Finishing...\n", a->id);   // once finished writing for 4 times print this
    pthread_mutex_lock(a->lock->mut);             // again lock for finally setting value of data =0
    a->lock->finishedWriting++;
    if (a->lock->finishedWriting == 5)
        data = 0;
    pthread_mutex_unlock(a->lock->mut);
    printf("Writer %d: Finished.\n", a->id); // finished completly
    printf("writer : %d waitingWriter : %d readers : %d \nwaitingReaders : %d finishedReading : %d finishedWriting : %d\n", a->lock->writers, a->lock->waitingWriter, a->lock->readers, a->lock->waitingReader, a->lock->finishedReading % 10, a->lock->finishedWriting);
    return (NULL);
}
rwl *initlock(void)
{
    rwl *lock;
    lock = (rwl *)malloc(sizeof(rwl)); // allocating memory
    if (lock == NULL)
        return (NULL);
    lock->mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (lock->mut == NULL)
    {
        free(lock);
        return (NULL);
    }
    lock->readMut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (lock->readMut == NULL)
    {
        free(lock);
        return (NULL);
    }
    lock->writeOK =
        (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    if (lock->writeOK == NULL)
    {
        free(lock->mut);
        free(lock);
        return (NULL);
    }
    lock->readOK =
        (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    lock->allRead =
        (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    if (lock->readOK == NULL)
    {
        free(lock->mut);
        free(lock->writeOK);
        free(lock);
        return (NULL);
    }
    pthread_mutex_init(lock->mut, NULL);
    pthread_mutex_init(lock->readMut, NULL);
    pthread_cond_init(lock->writeOK, NULL);
    pthread_cond_init(lock->readOK, NULL);
    pthread_cond_init(lock->allRead, NULL);
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
    pthread_mutex_lock(lock->mut);
    lock->waitingReader++;
    if (lock->writers || lock->waitingWriter)
    {
        do
        {
            printf("reader %d blocked.\n", d);
            pthread_cond_wait(lock->readOK, lock->mut);
            printf("reader %d unblocked.\n", d);
        } while (lock->writers);
    }
    lock->waitingReader--;
    lock->readers++;
    // printf("writer : %d waitingWriter : %d readers : %d \nwaitingReaders : %d finishedReading : %d finishedWriting : %d\n", lock->writers, lock->waitingWriter, lock->readers, lock->waitingReader, lock->finishedReading % 10, lock->finishedWriting);
    pthread_mutex_unlock(lock->mut);
    return;
}
void writelock(rwl *lock, int d)
{
    pthread_mutex_lock(lock->mut);
    lock->waitingWriter++;
    while (lock->readers || lock->writers)
    {
        printf("writer %d blocked.\n", d);
        pthread_cond_wait(lock->writeOK, lock->mut);
        printf("writer %d unblocked.\n", d);
    }
    lock->waitingWriter--;
    lock->writers++;
    // printf("writer : %d waitingWriter : %d readers : %d \nwaitingReaders : %d finishedReading : %d finishedWriting : %d\n", lock->writers, lock->waitingWriter, lock->readers, lock->waitingReader, lock->finishedReading % 10, lock->finishedWriting);
    pthread_mutex_unlock(lock->mut);
    return;
}
void readunlock(rwl *lock)
{
    pthread_mutex_lock(lock->mut);
    lock->readers--;
    lock->finishedReading++;
    if (lock->finishedReading % SIMREAD == 0)
        pthread_cond_signal(lock->writeOK);
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