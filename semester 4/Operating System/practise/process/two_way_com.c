#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <setjmp.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{

    int p1[2]; // c--p
    int p2[2]; // p--c
    if (pipe(p1) == -1)
    {
        return 1;
    }
    if (pipe(p2) == -1)
    {
        return 1;
    }
    int pid = fork();
    if (pid == -1)
    {
        return 2;
    }
    if (pid == 0)
    {
        close(p1[0]);
        close(p2[1]);
        // child process
        int x;
        if (read(p2[0], &x, sizeof(x)) == -1)
        {
            return 3;
        }
        printf("recieved %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1)
        {
            return 4;
        }
        printf("wrote %d\n", x);
        close(p1[1]); // write
        close(p2[0]); // read
    }
    else
    {
        close(p1[1]); // write
        close(p2[0]); // read
        // parent process
        srand(time(NULL));
        int y = rand() % 10;
        if (write(p2[1], &y, sizeof(y)) == -1)
        {
            return 5;
        }
        // printf("wrote %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1)
        {
            return 6;
        }
        printf("result is %d\n", y);
        close(p1[0]); // write
        close(p2[1]); // read
        wait(NULL);
    }
    close(p1[0]);
    close(p1[1]);

    return 0;
}
