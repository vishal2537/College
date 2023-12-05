#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // first the main process is run printing from 6 to 10
    // then fork will run and a child process is execute

    int id = fork();
    int n;
    // printf("%d --\n", id);
    if (id == 0)
    {
        n = 1; // for child process
    }
    else
    {
        n = 6; // for main process
    }
    if (id != 0)
    {
        wait();
    } 
    int i;
    for (i = n; i < n + 5; i++)
    {
        // printf("%d %d \n", i, id);
        printf("%d ", i);

        fflush(stdout); // it is printed on the terminal
    }

    return 0;
}