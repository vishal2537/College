#include <stdio.h>

int main()
{
    char a[100], b[10];
    int flag, i, j;
    printf("ENTR THE SENTENCE :\n");
    gets(a);
    printf("\nENTER THE STRING TO BE SEARCHED : \n");
    gets(b);
    for (i = 0; a[i] != '\0'; i++)
    {
        for (j = 0; b[j] != '\0'; j++)
        {
            if (a[i + j] != b[j])
            {
                break;
            }
        }
        if (b[j] == '\0')
        {
            printf("STRING FOUND AT POSITION : %d\n", i);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("STRING NOT FOUND !!");
    }
    return 0;
}