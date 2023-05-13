#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        swap(&a[i], &a[k]);
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("enter number of element :");
    scanf("%d", &n);
    int a[n];
    printf("enter number :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    print_array(a, n);
    selection_sort(a, n);
    print_array(a, n);

    return 0;
}