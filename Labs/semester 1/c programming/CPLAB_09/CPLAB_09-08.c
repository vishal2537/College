#include <stdio.h>
#include <string.h>

int main()
{
    char a[100][100], t[100];
    int i, j, k, n;
    printf("ENTER THE VALUE OF n : ");
    scanf("%d", &n);
    printf("ENTER %d STRINGS : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", &a[i]);
    }
    printf("BEFORE SORTING : \n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", a[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            k = strcmp(a[j], a[j + 1]);
            if (k > 0)
            {
                strcpy(t, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], t);
            }
        }
    }

    printf("AFTER SORTING : \n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", a[i]);
    }

    return 0;
}