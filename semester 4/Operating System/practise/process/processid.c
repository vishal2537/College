#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int id = fork();
    if (id == 0)
    {
        sleep(1);
    }
    printf("curent id : %d parent id : %d \n", getpid(),
           getppid());

    // if (id != 0)
    // {
    //     wait(NULL);
    // }
    int res = wait(NULL); // process id which we are waiting for
    if (res == -1)
    {
        printf("no children is wait for\n");
    }
    else
    {
        printf("%d finished execution\n", res);
    }

    return 0;
}