#include <stdio.h>

int main()
{

    int m, n, count = 0;
    printf("Enter the size of array \n");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int i, j, flag = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (count != 0)
            {
                break;
            }
            if (arr[i][j] != arr[i + 1][j + 1])
            {
                printf("Matrix is not Toeplitz\n");
                count++;
            }
        }
    }
    if (count == 0)
    {
        printf("Matrix is Toeplitz\n");
    }

    return 0;
}