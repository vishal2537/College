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
    int pid = fork();
    if (pid == -1)
    {
        return 1;
    }
    if (pid == 0)
    {
        // child process
        int err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
        if (err == -1)
        {
            printf("could not find program to execute \n");
            return 2;
        }
    }
    else
    {
        int wstatus; // parent processs
        wait(&wstatus);
        if (WIFEXITED(wstatus))
        {
            int statuscode = WEXITSTATUS(wstatus);
            if (statuscode == 0)
            {
                printf("success..\n");
            }
            else
            {
                printf("failure... with status code %d\n", statuscode);
            }
        }
        printf("some post processing\n");
    }

    return 0;
}