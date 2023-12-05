#include <stdio.h>

int comparison(char *a, char *b)
{
    int flag = 0;
    while (*a != '\0' || *b != '\0')
    {
        if (*a == *b)
        {
            a++;
            b++;
        }
        else if ((*a == '\0' && *b != '\0') || (*a != '\0' && *b == '\0') || *a != *b)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    char a[100], b[100];
    printf("PROGRAM FOR THE COMPARISON OF TWO SENTENCE \n");
    printf("\nENTER THE FIRST SENTENCE : ");
    gets(a);
    printf("\nENTER THE SECOND SENTENCE : ");
    gets(b);

    int temp=comparison(a, b);

    if (temp == 0)
    {
        printf("BOTH ARE EQUAL \n");
    }

    else if (temp == 1)
    {
        printf("BOTH ARE NOT EQUAL.\n");
    }

    return 0;
}