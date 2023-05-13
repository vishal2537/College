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

int x = 0;
void handle_sigusr1(int sig)
{
    if (x == 0)
    {
        printf("rememeebr that multiplication is repetitive addition \n");
    }
}

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == -1)
    {
        return 1;
    }
    if (pid == 0)
    {
        // child process
        sleep(5);
        kill(getppid(), SIGUSR1);
    }
    else
    {
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESETHAND;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);

        // parent process
        int x;
        printf("what is the result of 3 * 5 :");
        scanf("%d", &x);
        if (x == 15)
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
        wait(NULL);
    }

    return 0;
}