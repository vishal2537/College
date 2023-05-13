#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex;

void *routine(void *arg)
{
    if (pthread_mutex_trylock(&mutex) == 0)
    {
        printf("got lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    else
    {
        printf("didn't get lock\n");
    }
}

int main(int argc, char *argv[])
{
    pthread_t th[4];
    int i;
    for (i = 0; i < 4; i++)
    {
        int *a = malloc(sizeof(int));
        if (pthread_create(&th[i], NULL, &routine, a) != 0)
        {
            perror("failed to create thread");
        }
    }
    for (i = 0; i < 4; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("failed to join thread");
        }
    }

    return 0;
}