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
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
        printf("this should not print on terminal\n");
        // execlp("ping", "ping", "-c", "3", "google.com", NULL);
    }
    else
    {
        // parent processs
        wait(NULL);
        printf("success..\n");

        printf("some post processing\n");
    }

    // printf("success..\n");
    return 0;
}