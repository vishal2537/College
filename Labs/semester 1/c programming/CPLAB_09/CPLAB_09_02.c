
#include <stdio.h>
void length(char *string)
{
    int i, length = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        length++;
    }
    printf("the length of %s = %d\n", string, length);
}
void main()
{
    char string[1000];
    printf("Enter a string \n");
    gets(string);
    length(string);
}
