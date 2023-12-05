#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int l, int mid, int h)
{
    int b[100];
    int i = l, j = mid + 1, k = l;
    while (l <= mid && j <= h)
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
    mid = (l + h) / 2;
    if (l < h)
    {
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
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