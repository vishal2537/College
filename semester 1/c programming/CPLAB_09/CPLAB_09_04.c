// With a function to copy a string to another string without
// using library functions related to string manipulation.

#include <stdio.h>
void string(char *a)
{
    int i;
    char b[100];
    for (i = 0; a[i] != '\0'; ++i)
    {
        b[i] = a[i];
    }
    b[i] = '\0';
    printf("ENTERED STRING IS : %s", b);
}
int main()
{
    char a[1000], b[1000];
    printf("ENTER THE SENTENCE : ");
    gets(a);
    string(a);

    return 0;
}