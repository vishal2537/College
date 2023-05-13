#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row = 2, col = 3;
    int *arr = (int *)malloc(row * col * sizeof(int));
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            *(arr + i * col + j) = i + j;
    printf("element of two 2d array :\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", *(arr + i * col + j));
        }
        printf("\n");
    }
    return 0;
}































    // free(arr);
