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

void handle_sigtstp(int sig)
{
    printf("stop not allowed\n");
}

void handle_sigcont(int sig)
{
    printf("inout number : \n");
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    // sa.sa_handler = &handle_sigtstp;
    sa.sa_handler = &handle_sigcont;
    sa.sa_flags = SA_RESTART;
    // sigaction(SIGTSTP,&sa,NULL);
    sigaction(SIGCONT, &sa, NULL);

    // signal(SIGTSTP, &handle_sigtstp);

    int x;
    printf("inout number : ");
    scanf("%d", &x);
    printf("result %d * 5 = %d\n", x, x * 5);

    return 0;
}