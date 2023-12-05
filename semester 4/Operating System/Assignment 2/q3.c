#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ct = -1e5;
    if (argc > 1)
    {
        ct = atoi(argv[1]);
    }

    int c;
    while (ct && (c = getchar()) != EOF)
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
        ct++;
    }
    exit(0);
}
