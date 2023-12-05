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
    char *arr[] = {
        "ping",
        "google.com", NULL};
    // char env[] = {"test = environment variable", NULL};
    execvp("ping", arr);
    // execlp("ping", "ping", "google.com", NULL);
    printf("ping finished executing..\n");
    return 0;
}