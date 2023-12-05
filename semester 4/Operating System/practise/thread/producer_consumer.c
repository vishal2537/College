//  1--> manage shared memory access
//  2--> check for if buffer  full  (two producer and only one consumer)
//  3--> cheking fo if buffer is empty

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define THREAD_NUM 2
sem_t semempty;
sem_t semfull;

int buffer[10];
int count = 0;
pthread_mutex_t mutexbuffer;

void *producer(void *args)
{
    while (1)
    {
        // producer
        int x = rand() % 100;
        sleep(1);

        // add to buffer
        sem_wait(&semempty);
        pthread_mutex_lock(&mutexbuffer);
        // if (count < 10)
        // {
        buffer[count] = x;
        count++;
        // }
        // else
        // {
        // printf("skipped %d\n", x);
        // }
        pthread_mutex_unlock(&mutexbuffer);
        sem_post(&semfull);
    }
}
void *consumer(void *args)
{
    while (1)
    {
        int y;
        // remove from the buffer
        sem_wait(&semfull);
        pthread_mutex_lock(&mutexbuffer);
        // if (count > 0)
        // {
        y = buffer[count - 1];
        count--;
        // }
        pthread_mutex_unlock(&mutexbuffer);
        sem_post(&semempty);

        // consume
        printf("got number y %d\n", y);
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    pthread_mutex_init(&mutexbuffer, NULL);
    pthread_t th[THREAD_NUM];
    sem_init(&semempty, 0, 10);
    sem_init(&semfull, 0, 0);

    int i;
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (i > 0)
        {
            if (pthread_create(&th[i], NULL, &producer, NULL) != 0)
            {
                perror("failed to create thread\n");
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &consumer, NULL) != 0)
            {
                perror("failed to create thread\n");
            }
        }
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("failed to join thread\n");
        }
    }
    sem_destroy(&semempty);
    sem_destroy(&semfull);

    pthread_mutex_destroy(&mutexbuffer);

    return 0;
}
