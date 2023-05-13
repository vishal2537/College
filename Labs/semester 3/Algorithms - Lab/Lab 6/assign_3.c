#include <stdio.h>
#include <limits.h>

int matrix_Chain_Order(int p[], int n)
{
    int m[n][n];
    int i, j, k, l, q;

    for (i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (l = 2; l < n; l++)
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
                // printf("----%d----", m[i][j]);
            }
        }
    }
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         printf("--%d-- ",m[i][j]);
    //     }
    //     printf("\n");
    // }
    
    return m[1][n - 1];
}


int main()
{
    int n;
    printf("ENTER NUMBER OF ELEMENT IN ARRAY  : ");
    scanf("%d", &n);
    int a[n];
    printf("ENTER ELEMNETS : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("ENTER MINIMUM NUMBER OF MULTIPLICATION : ");
    printf("  %d  ", matrix_Chain_Order(a, n));

    return 0;
}