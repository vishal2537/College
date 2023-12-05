#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int id = fork();
    if (id != 0)
    {
        fork();
    }
    printf("hello : %d\n", id);
    
    // id 0 means child process and if id != 0 means main process
    //  let n be the number of times to call fork the 2^n process created

    // int id1 = fork();
    // int id2 = fork();
    // int id3 = fork();
    // int id4 = fork();
    // printf("hello : %d %d %d %d \n", id1, id2, id3, id4);

    // if (id == 0)
    // {
    //     printf("hello from child process\n");
    // }
    // else
    // {
    //     printf("hello form main process\n");
    // }

    return 0;
}