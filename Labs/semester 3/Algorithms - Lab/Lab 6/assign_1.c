#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int cc[100][100];
int MCM(int p[], int i, int j)
{
    if (i == j)
    {
        cc[i][j]++;
        return 0;
    }
    int k;
    int min = INT_MAX;
    int c;

    for (k = i; k < j; k++)
    {
        c = MCM(p, i, k) + MCM(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (c < min)
        {
            min = c;
        }
    }
    cc[i][j]++;
    return min;
}

int main()
{
    int n;
    printf("ENTER NUMBER OF MATRIX  : ");
    scanf("%d", &n);
    int a[n + 1];
    printf("ENTER ELEMNETS : ");
    for (int i = 0; i < n + 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("MINIMUM NUMBER OF MULTIPLICATION : ");
    int x = MCM(a, 1, n);
    printf("%d \n", x);
    printf("SUBPROBLEMS : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            printf("--%d-- ", cc[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 30 35 15 5 10 20 25