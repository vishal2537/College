#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 0;
    while (--argc > 0)
    {
        if (*(argv + i)[0] == '-')
        {
            *++argv;
            continue;
        }
        else
        {
            printf((argc > 1) ? "%s " : "%s\n", *++argv);
        }
        i++;
    }
    return 0;
}
