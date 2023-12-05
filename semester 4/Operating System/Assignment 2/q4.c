#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int fd_in, fd_out;
    int pid1, pid2;
    if (argc != 3)
    {
        fprintf(stderr, "ERROR: MISSING FILE ARGUEMENT\n");
    }

    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1)
    {
        perror("open");
        return 1;
    }

    fd_out = creat(argv[2], 0655);
    if (fd_out == -1)
    {
        perror("creat");
        return 2;
    }

    if (dup2(fd_in, STDIN_FILENO) == -1)
    {
        perror("dup2");
        return 1;
    }
    close(fd_in);

    if (dup2(fd_out, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        return 1;
    }
    close(fd_out);

    if (pipe(fd) == -1)
    {
        return 1;
    }

    // Fork first child
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        return 3;
    }
    if (pid1 == 0)
    {
        close(fd[1]); // Close write end of pipe
        if (dup2(fd[0], STDIN_FILENO) == -1)
        {
            perror("dup2");
            return 1;
        }
        close(fd[0]); // Close read end of pipe
        char *args[] = {"./q2", NULL};
        execvp(args[0], args); // count_number_of_nonalphabets function
        return 0;
    }

    // Fork second child
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("fork");
        return 1;
    }
    if (pid2 == 0)
    {
        close(fd[0]); // Close read end of pipe
        if (dup2(fd[1], STDOUT_FILENO) == -1)
        {
            perror("dup2");
            return 1;
        }
        close(fd[1]); // Close write end of pipe
        char *args[] = {"./q3", NULL};
        execvp(args[0], args); // convert_case_of_alphabets function
        return 0;
    }
    close(fd[0]); // Close read end of pipe
    close(fd[1]); // Close write end of pipe
    wait(NULL);
    wait(NULL);

    return 0;
}