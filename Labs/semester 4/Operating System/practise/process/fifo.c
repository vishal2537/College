#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
    if (mkfifo("myfifo", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("could not create fifo file\n");
            return 1;
        }
    }

    printf("opening....");

    int fd = open("myfifo1", O_WRONLY);
    printf("opened....");

    int x;
    if (write(fd, &x, sizeof(x)) == -1)
    {
        return 2;
    }
    printf("closing...");
    close(fd);
    printf("closed...");
  
    return 0;
}
