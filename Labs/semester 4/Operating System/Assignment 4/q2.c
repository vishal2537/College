#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Define constants for the number of times each reader/writer will access the data.
#define MAXCOUNT 5
#define READER1 100000
#define READER2 200000
#define READER3 400000
#define READER4 800000
#define WRITER1 150000

// Define a struct for the readers/writers lock (rwl).
typedef struct
{
    pthread_mutex_t *mut;             // mutual exclusion variable
    int writers;                      // the number of writers that have acquired the lock
    int readers;                      // the number of readers that have acquired the lock
    int waiting;                      // the number of waiting threads
    pthread_cond_t *writeOK, *readOK; // conditional variables
} rwl;

// Define functions for creating, locking, unlocking, and deleting the lock.
rwl *initlock(void);
void readlock(rwl *lock, int d);
void writelock(rwl *lock, int d);
void readunlock(rwl *lock);
void writeunlock(rwl *lock);
void deletelock(rwl *lock);

// Define a struct for the arguments that will be passed to each reader/writer thread.
typedef struct
{
    rwl *lock;
    int id;
    long delay;
} rwargs;

// Define functions for creating and executing the reader/writer threads.
rwargs *newRWargs(rwl *l, int i, long d);
void *reader(void *args);
void *writer(void *args);

// Define a global variable to hold the data that will be accessed.
static int data = 1;

int main()
{
    pthread_t r1, r2, r3, r4, w1;
    rwargs *a1, *a2, *a3, *a4, *a5;
    rwl *lock;

    // Initialize the lock and its arguments.
    lock = initlock();
    a1 = newRWargs(lock, 1, WRITER1);
    a2 = newRWargs(lock, 1, READER1);
    a3 = newRWargs(lock, 2, READER2);
    a4 = newRWargs(lock, 3, READER3);
    a5 = newRWargs(lock, 4, READER4);

    // Create and execute the reader/writer threads.
    pthread_create(&w1, NULL, writer, a1);
    pthread_create(&r1, NULL, reader, a2);
    pthread_create(&r2, NULL, reader, a3);
    pthread_create(&r3, NULL, reader, a4);
    pthread_create(&r4, NULL, reader, a5);

    // Wait for all threads to finish.
    pthread_join(w1, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(r3, NULL);
    pthread_join(r4, NULL);

    // Free the lock and its arguments.
    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    return 0;
}

// Allocate memory for the reader/writer arguments and initialize them.
rwargs *newRWargs(rwl *l, int i, long d)
{
    rwargs *args;
    args = (rwargs *)malloc(sizeof(rwargs));
    if (args == NULL)
    {
        return (NULL);
    }
    args->lock = l;
    args->id = i;
    args->delay = d;
    return (args);
}

// The function simulates a reader thread by repeatedly acquiring a read lock, reading
// the shared data, releasing the lock, and printing the data.
// It stops when the data is 0.

void *reader(void *args)
{
    rwargs *a;
    int d;
    a = (rwargs *)args;
    do
    {
        readlock(a->lock, a->id);
        d = data;
        usleep(a->delay);
        readunlock(a->lock);
        printf("Reader % d: Data = %d\n", a->id, d);
        usleep(a->delay);
    } while (d != 0);
    printf("Reader % d: Finished.\n", a->id);
    return (NULL);
}

// The function simulates a writer thread by repeatedly acquiring a write lock, writing to the shared data, releasing the lock, and printing the data.
// It stops when it has written to the maximum value and then sets the data to 0.

void *writer(void *args)
{
    rwargs *a;
    int i;
    a = (rwargs *)args;
    for (i = 2; i < MAXCOUNT; i++)
    {
        writelock(a->lock, a->id);
        data = i;
        usleep(a->delay);
        writeunlock(a->lock);
        printf("Writer % d: Wrote % d\n", a->id, i);
        usleep(a->delay);
    }
    printf("Writer % d: Finishing...\n", a->id);
    writelock(a->lock, a->id);
    data = 0;
    writeunlock(a->lock);
    printf("Writer % d: Finished.\n", a->id);
    return (NULL);
}

// Allocate memory for the reader/writer lock and initialize them.
rwl *initlock(void)
{
    rwl *lock;

    lock = (rwl *)malloc(sizeof(rwl));
    if (lock == NULL)
        return (NULL);
    lock->mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (lock->mut == NULL)
    {
        free(lock);
        return (NULL);
    }
    lock->writeOK = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    if (lock->writeOK == NULL)
    {
        free(lock->mut);
        free(lock);
        return (NULL);
    }
    lock->readOK = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
    if (lock->writeOK == NULL)
    {
        free(lock->mut);
        free(lock->writeOK);
        free(lock);
        return (NULL);
    }
    pthread_mutex_init(lock->mut, NULL);
    pthread_cond_init(lock->writeOK, NULL);
    pthread_cond_init(lock->readOK, NULL);
    lock->readers = 0;
    lock->writers = 0;
    lock->waiting = 0;
    return (lock);
}

// Acquires a read lock for the specified rwl object, blocking if necessary until
// a read lock can be acquired. Once acquired, increments the number of readers.
// lock the rwl object to acquire the lock for
//  d identifier of the reader thread

void readlock(rwl *lock, int d)
{
    pthread_mutex_lock(lock->mut);
    if (lock->writers || lock->waiting)
    {
        do
        {
            printf("reader % d blocked.\n", d);
            pthread_cond_wait(lock->readOK, lock->mut);
            printf("reader % d unblocked.\n", d);
        } while (lock->writers);
    }
    lock->readers++;
    pthread_mutex_unlock(lock->mut);
    return;
}

// Acquires a write lock for the specified rwl object, blocking if necessary until
// a write lock can be acquired. Once acquired, increments the number of writers.
//  lock the rwl object to acquire the lock for
//  d identifier of the writer thread

void writelock(rwl *lock, int d)
{
    pthread_mutex_lock(lock->mut);
    lock->waiting++;
    while (lock->readers || lock->writers)
    {
        printf("writer % d blocked.\n", d);
        fflush(NULL);
        pthread_cond_wait(lock->writeOK, lock->mut);

        printf("writer % d unblocked.\n", d);
    }
    lock->waiting--;
    lock->writers++;
    pthread_mutex_unlock(lock->mut);
    return;
}

// Releases a read lock for the specified rwl object, decrementing the number of readers.
// If there are no more readers, signals a waiting writer thread.
// lock the rwl object to release the lock for

void readunlock(rwl *lock)
{
    pthread_mutex_lock(lock->mut);
    lock->readers--;
    if (lock->readers == 0)
        pthread_cond_signal(lock->writeOK);
    pthread_mutex_unlock(lock->mut);
}

// Releases a write lock for the specified rwl object, decrementing the number of writers.
// Signals all waiting reader threads to wake up.
//  lock the rwl object to release the lock for

void writeunlock(rwl *lock)
{
    pthread_mutex_lock(lock->mut);
    lock->writers--;
    pthread_cond_broadcast(lock->readOK);
    pthread_mutex_unlock(lock->mut);
}

// Deletes the specified rwl object, destroying the associated mutex and condition variables
// and freeing the memory used by the object.
//  lock the rwl object to delete

void deletelock(rwl *lock)
{
    pthread_mutex_destroy(lock->mut);
    pthread_cond_destroy(lock->readOK);
    pthread_cond_destroy(lock->writeOK);
    free(lock);
    return;
}