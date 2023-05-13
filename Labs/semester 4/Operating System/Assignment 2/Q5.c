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

jmp_buf env;
void handler()
{
    fprintf(stderr, "TIME OUT CHILDEREN KILL\n");
    longjmp(env, 1);
}

int check_number(char str[])
{
    if (str[0] != '-')
        return 0;
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]) == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int fd[2];
    int fd_in, fd_out;
    pid_t pid1, pid2;
    int status;
    int i = 1;
    // int length = -1;

    if (argc >= 5 || (argc == 4 && !check_number(argv[i])))
    {
        fprintf(stderr, "INVALID FILE ARGUEMENT\n");
        exit(1);
    }
    else if (argc == 4)
    {
        i++;
    }
    // Open first file
    if (argc > 1)
    {

        fd_in = open(argv[i], O_RDONLY);
        if (fd_in == -1)
        {
            perror("open");
            exit(1);
        }
        // Dup stdin to fd_in
        if (dup2(fd_in, STDIN_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }
        close(fd_in);
    }

    // Create second file
    if (argc > 2)
    {
        fd_out = creat(argv[i + 1], 0644);
        if (fd_out == -1)
        {
            perror("creat");
            exit(1);
        }
        // Dup stdout to fd_out
        if (dup2(fd_out, STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }
        close(fd_out);
    }
    // Create pipe
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    signal(SIGALRM, handler);

    if (setjmp(env) != 0)
    {
        /* longjmp below causes setjmp to return here */
        /* kill children ... */
        if (pid1)
        {
            kill(pid1, SIGKILL);
        }
        if (pid2)
        {
            kill(pid2, SIGKILL);
        }
        /* wait loop (as below) for children ... */
        while ((pid1 = wait(&status)) > 0)
            ;
        while ((pid2 = wait(&status)) > 0)
            ;
        exit(1);
    }
    /* setjmp returns here first time called */

    // Fork first child
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        exit(1);
    }
    if (pid1 == 0)
    {
        // Child 1: count
        close(fd[1]); // Close write end of pipe
        if (dup2(fd[0], STDIN_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }
        close(fd[0]); // Close read end of pipe
        if (argc < 4)
        {
            char *args[] = {"./q2", NULL};
            execv(args[0], args);
        }
        else if (check_number(argv[1]))
        {
            char *args[] = {"./q2", argv[1], NULL};
            execv(args[0], args);
        }
        exit(0);
    }

    // Fork second child
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("fork");
        exit(1);
    }
    if (pid2 == 0)
    {
        close(fd[0]); // Close read end of pipe
        if (dup2(fd[1], STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }
        close(fd[1]); // Close write end of pipe
        if (!check_number(argv[1]))
        {
            char *args[] = {"./q3", NULL};
            execv(args[0], args);
        }
        else
        {
            char *args[] = {"./q3", argv[1], NULL};
            execv(args[0], args);
        }
        exit(1);
    }

    // Parent: driver
    close(fd[0]); // Close read end of pipe
    close(fd[1]); // Close write end of pipe

    alarm(15);
    while ((pid1 = wait(&status)) > 0)
    {
        fprintf(stderr, "CHILD_PID = %d REAPED WITH EXIT STATUS = %d\n", pid1, WEXITSTATUS(status));
        if (WEXITSTATUS(status) == 2)
        {
            kill(pid2, SIGKILL);
        }
    }
    while ((pid2 = wait(&status)) > 0)
    {
        fprintf(stderr, "CHILD_PID = %d REAPED WITH EXIT STATUS = %d\n", pid2, WEXITSTATUS(status));
    }
    alarm(0);
    exit(0);
}
