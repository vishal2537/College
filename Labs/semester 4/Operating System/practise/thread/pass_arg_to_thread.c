#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{
    sleep(1);
    int index = *(int *)arg;
    printf("%d \n ", prime[index]);
    free(arg);
}

int main(int argc, char *argv[])
{
    pthread_t th[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        int *a = malloc(sizeof(int));
        if (pthread_create(&th[i], NULL, &routine, a) != 0)
        {
            perror("failed to create thread");
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("failed to join thread");
        }
    }

    return 0;
}