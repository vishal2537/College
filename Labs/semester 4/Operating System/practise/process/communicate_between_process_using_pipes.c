#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd[2];
    // save the file discriptor
    // a pipe  should have two end so we made array of two
    // fd[0] : read
    // fd[1] : write
    // pipe();

    if (pipe(fd) == -1)
    {
        printf("an error occured while opening the pipe\n");
        return 1;
    }
    int id = fork();
    if (id == -1)
    {
        printf("an error occured with fork\n");
        return 4;
    }

    if (id == 0)
    {
        close(fd[0]); // as a pipe always  close from end
        int x;
        printf("input a number : ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("an error occured with writing to pipe\n");
            return 2;
        }

        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("an error occured with reading to pipe\n");
            return 2;
        }
        y = y * 3;
        close(fd[0]);
        printf("got from the child process %d\n", y);
    }

    return 0;
}