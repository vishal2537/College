#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int sub_problem[100][100];
int dp[100][100];
int MCM(int p[], int i, int j)
{
    if (i == j)
    {
        sub_problem[i][j]++;
        return 0;
    }
    else if (dp[i][j] != 0)
    {
        return dp[i][j];
        // sub_problem[i][j]++;
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], MCM(p, i, k) + MCM(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    sub_problem[i][j]++;
    return dp[i][j];
}

int main()
{
    int n;
    printf("ENTER NUMBER OF MATRIX  : ");
    scanf("%d", &n);
    int a[n + 1];
    printf("ENTER ELEMENTS : ");
    for (int i = 0; i < n + 1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("ENTER MINIMUM NUMBER OF MULTIPLICATION : ");
    int x = MCM(a, 1, n);
    printf("%d \n", x);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            printf("--%d-- ", dp[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            printf("--%d-- ", sub_problem[i][j]);
        }
        printf("\n");
    }

    return 0;
}
