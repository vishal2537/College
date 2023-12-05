#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void *fuel_filling(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 30;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_broadcast(&condFuel);
        sleep(1);
    }
}

void *car(void *arg)
{
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40)
    {
        printf("No fuel. Waiting...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
        // Equivalent to:
        // pthread_mutex_unlock(&mutexFuel);
        // wait for signal on condFuel
        // pthread_mutex_lock(&mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char *argv[])
{
    pthread_t th[6];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    for (int i = 0; i < 6; i++)
    {
        if (i == 4 || i == 5)
        {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
            {
                perror("Failed to create thread");
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0)
            {
                perror("Failed to create thread");
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <errno.h>

// pthread_mutex_t mutex_fuel;
// pthread_cond_t condfuel;
// int fuel = 0;

// void *fuel_filling(void *arg)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         pthread_mutex_lock(&mutex_fuel);
//         fuel += 60;
//         printf("filling fuel  %d  \n", fuel);
//         pthread_mutex_unlock(&mutex_fuel);
//         pthread_cond_signal(&condfuel);
//         sleep(1);
//     }
// }

// void *car(void *arg)
// {
//     pthread_mutex_lock(&mutex_fuel);
//     while (fuel < 40) // 45
//     {
//         printf("no fuel. waitinng...\n");
//         pthread_cond_wait(&condfuel, &mutex_fuel);

//         // equivalent to
//         // pthread_mutex_unlock(&mutex_fuel);
//         // wait for signal on condfuel
//         // pthread_mutex_lock(&mutex_fuel);
//         //
//     }
//     fuel -= 40;
//     printf("here to get fuel %d \n", fuel);
//     pthread_mutex_unlock(&mutex_fuel);
// }

// int main(int argc, char *argv[])
// {
//     pthread_t th[2];
//     pthread_mutex_init(&mutex_fuel, NULL);
//     pthread_cond_init(&condfuel, NULL);
//     int i;
//     for (i = 0; i < 5; i++)
//     {
//         if (i == 1)
//         {
//             if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
//             {
//                 perror("failed to create thread\n");
//             }
//         }
//         else
//         {
//             if (pthread_create(&th[i], NULL, &car, NULL) != 0)
//             {
//                 perror("failed to create thread\n");
//             }
//         }
//     }
//     for (i = 0; i < 5; i++)
//     {
//         if (pthread_join(th[i], NULL) != 0)
//         {
//             perror("failed to join thread\n");
//         }
//     }

//     pthread_mutex_destroy(&mutex_fuel);
//     pthread_cond_destroy(&condfuel);
//     return 0;
// }