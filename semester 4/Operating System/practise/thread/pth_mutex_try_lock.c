#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutex_fuel;
pthread_cond_t condfuel;
int fuel = 0;

void *fuel_filling(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex_fuel);
        fuel += 15;
        printf("filling fuel  %d  \n", fuel);
        pthread_mutex_unlock(&mutex_fuel);
        pthread_cond_signal(&condfuel);
        sleep(1);
    }
}

void *car(void *arg)
{
    pthread_mutex_lock(&mutex_fuel);
    while (fuel < 40)
    {
        printf("no fuel. waitinng...\n");
        // sleep(1);
        pthread_cond_wait(&condfuel, &mutex_fuel);

        // equivalent to
        // pthread_mutex_unlock(&mutex_fuel);
        // wait for signal on condfuel
        // pthread_mutex_lock(&mutex_fuel);
        //
    }
    fuel -= 40;
    printf("here to get fuel %d \n", fuel);

    // if (fuel >= 40)
    // {
    //     fuel -= 40;
    //     printf("here to get fuel %d \n", fuel);
    // }
    // else
    // {
    //     printf("no fuel\n");
    // }
    pthread_mutex_unlock(&mutex_fuel);
}

int main(int argc, char *argv[])
{
    pthread_t th[2];
    pthread_mutex_init(&mutex_fuel, NULL);
    pthread_cond_init(&condfuel, NULL);
    int i;
    for (i = 0; i < 2; i++)
    {
        if (i == 1)
        {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
            {
                perror("failed to create thread\n");
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0)
            {
                perror("failed to create thread\n");
            }
        }
    }
    for (i = 0; i < 2; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("failed to join thread\n");
        }
    }

    pthread_mutex_destroy(&mutex_fuel);
    pthread_cond_destroy(&condfuel);
    return 0;
}