#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int b[100];

    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    for (; i <= mid; i++)
    {
        b[k++] = a[i];
    }
    for (; j <= h; j++)
    {
        b[k++] = a[j];
    }
    for (i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}

void merge_sort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, h);
        merge(a, l, mid, h);
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
    merge_sort(a, 0, n);
    print_array(a, n);

    return 0;
}