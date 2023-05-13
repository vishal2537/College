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
        while (1)
        {
            printf("some text \n");
            usleep(50000);
        }
    }
    else
    {
        kill(pid, SIGSTOP);
        int t;
        do
        {
            printf("time in sec of execution : ");
            scanf("%d", &t);
            if (t > 0)
            {
                kill(pid, SIGCONT);
                sleep(t);
                kill(pid, SIGSTOP);
            }
        } while (t > 0);
        // kill(pid, SIGSTOP); // stop actul process
        // sleep(1);
        // kill(pid, SIGCONT);
        // sleep(1);
        kill(pid, SIGKILL); // send signal to process and process execute it
        wait(NULL);
    }

    return 0;
}