//print alphabets from z to a using while loop.

#include <stdio.h>

int main()
{
    char ch = 'z';

    printf("Lowercase English Alphabets:\n");
    while(ch >= 'a')
    {
        printf("%c ", ch);
        ch--;
    }
    printf("\n");

    return 0;
}
