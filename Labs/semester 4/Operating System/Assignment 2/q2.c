#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count = 0;
    int ct = -1e5;
    if (argc > 1)
    {
        ct = atoi(argv[1]);
    }

    char c;
    while (ct && (c = getchar()) != EOF)
    {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
        {
            count++;
        }
        putchar(c);
        ct++;
    }
    fprintf(stderr, "Non-alphabetic character count: %d\n", count);
    exit(0);
}
