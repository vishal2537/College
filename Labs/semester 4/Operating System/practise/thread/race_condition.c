#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// gcc -S race_condition.c

// gcc -g -pthread main.c -o main
int mails = 0;
void *routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        mails++;
        //                  t1          t2
        // read mails        23          24
        // increment         23          24
        // write mails       24          25
    }
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
    {
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
    {
        return 2;
    }

    if (pthread_join(t1, NULL) != 0)
    {
        return 3;
    }
    if (pthread_join(t2, NULL) != 0)
    {
        return 4;
    }
    printf("number of mails : %d\n", mails);

    return 0;
}