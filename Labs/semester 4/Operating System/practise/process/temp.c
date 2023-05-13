#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>

void convert()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (isupper(c))
        {
            c = tolower(c);
        }
        else if (islower(c))
        {
            c = toupper(c);
        }
        putchar(c);
    }
}

void count()
{
    int c, count = 0;
    while ((c = getchar()) != EOF)
    {
        if (!isalpha(c))
        {
            count++;
        }
        putchar(c);
    }
    fprintf(stderr, "final count = %d\n", count);
}

int main(int argc, char *argv[])
{
    int fd[2]; // save file discriptor
    int fd_in, fd_out;
    pid_t pid1, pid2;

    if (argc != 3)
    {
        fprintf(stderr, "Error: Missing file arguments\n");
        exit(1);
    }

    // Open first file
    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1)
    {
        perror("open");
        exit(1);
    }

    // Create second file
    fd_out = creat(argv[2], 0644);
    if (fd_out == -1)
    {
        perror("creat");
        exit(1);
    }

    // Dup stdin to fd_in
    if (dup2(fd_in, STDIN_FILENO) == -1)
    {
        perror("dup2");
        exit(1);
    }
    close(fd_in);

    // Dup stdout to fd_out
    if (dup2(fd_out, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        exit(1);
    }
    close(fd_out);

    // Create pipe
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

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
        count();      // Execute count function
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
        // Child 2: convert
        close(fd[0]); // Close read end of pipe
        if (dup2(fd[1], STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(1);
        }
        close(fd[1]); // Close write end of pipe
        convert();    // Execute convert function
        exit(0);
    }

    // Parent: driver
    close(fd[0]); // Close read end of pipe
    close(fd[1]); // Close write end of pipe
    int status;

    wait(&status); // Wait for first child
    wait(&status); // Wait for second child
    exit(0);
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>

void convert(void);
void count(void);

int main(int argc, char *argv[]) {
    int fd[2];
    int fd_in, fd_out;
    pid_t pid1, pid2;

    if (argc != 3) {
        fprintf(stderr, "Error: Missing file arguments\n");
        exit(1);
    }

    // Open first file
    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1) {
        perror("open");
        exit(1);
    }

    // Create second file
    fd_out = creat(argv[2], 0644);
    if (fd_out == -1) {
        perror("creat");
        exit(1);
    }

    // Dup stdin to fd_in
    if (dup2(fd_in, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }
    close(fd_in);

    // Dup stdout to fd_out
    if (dup2(fd_out, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(1);
    }
    close(fd_out);

    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    // Fork first child
    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(1);
    }
    if (pid1 == 0) {
        // Child 1: count
        close(fd[1]); // Close write end of pipe
        if (dup2(fd[0], STDIN_FILENO) == -1) {
            perror("dup2");
            exit(1);
        }
        close(fd[0]); // Close read end of pipe
        char *args[]={"./b",NULL};
        execvp(args[0],args);
        // count(); // Execute count function
        exit(0);
    }

    // Fork second child
    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(1);
    }
    if (pid2 == 0) {
        // Child 2: convert
        close(fd[0]); // Close read end of pipe
        if (dup2(fd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(1);
        }
        close(fd[1]); // Close write end of pipe
        char *args[]={"./c",NULL};
        execvp(args[0],args);
        // convert(); // Execute convert function
        exit(0);
    }

    // Parent: driver
    close(fd[0]); // Close read end of pipe
    close(fd[1]); // Close write end of pipe
    int status;
    wait(&status); // Wait for first child
    wait(&status); // Wait for second child
    exit(0);
}

void convert(void) {
    int c;
    while((c = getchar()) != EOF) {
        if (isupper(c)) {
            c = tolower(c);
        } else if (islower(c)) {
            c = toupper(c);
        }
        putchar(c);
    }
}

void count(void) {
    int c, count = 0;
    while((c = getchar()) != EOF) {
        if (!isalpha(c)) {
            count++;
        }
        putchar(c);
        
    }
    fprintf(stderr, "final count = %d\n", count);
}