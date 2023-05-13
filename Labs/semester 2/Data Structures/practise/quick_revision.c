#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (pivot < a[j]);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);
    swap(&a[l], &a[j]);

    return j;
}

void quick_sort(int a[], int l, int h)
{
    int parti;
    if (l < h)
    {
        parti = partition(a, l, h);
        quick_sort(a, l, parti);
        quick_sort(a, parti + 1, h);
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
    quick_sort(a, 0, n);
    print_array(a, n);

    return 0;
}