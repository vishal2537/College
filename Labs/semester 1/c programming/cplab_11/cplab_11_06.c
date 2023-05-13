#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(arr + i));
    }
    // increase the size of allocated memory
    arr = realloc(arr, 10 * sizeof(int));
    
     for (int i = 0; i < 10; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(arr + i));
    }

    return 0;
}








