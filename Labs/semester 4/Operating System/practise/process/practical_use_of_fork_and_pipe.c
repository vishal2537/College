#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 1, 2, 10, 11};
    int fd[2];
    int arrsize = sizeof(arr) / sizeof(int);
    int start, end;
    if (pipe(fd) == -1)
    {
        return 1;
    }

    int id = fork();
    if (id == -1)
    {
        return 2;
    }

    if (id == 0)
    {
        start = 0;
        end = start + arrsize / 2;
    }
    else
    {
        start = arrsize / 2;
        end = arrsize;
    }

    int sum = 0;
    int i;
    for (i = start; i < end; i++)
    {
        sum += arr[i];
    }
    printf("calculate partial sum : %d\n", sum);

    if (id == 0)
    {
        close(fd[0]);
        if (write(fd[1], &sum, sizeof(sum)) == -1)
        {
            return 3;
        }
        close(fd[1]);
    }
    else
    {
        int sumofchild;
        close(fd[1]);

        if (read(fd[0], &sumofchild, sizeof(sumofchild)) == -1)
        {
            return 4;
        }
        close(fd[0]);

        int totalsum = sum + sumofchild;
        printf("total sum : %d \n", totalsum);
        wait(NULL);
    }

    return 0;
}