#include <stdio.h>
#include <stdlib.h>

int size = 0;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int a[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (size == 1)
    {
        printf("only one element present !! ");
    }
    else
    {
        if (l < size && a[l] > a[largest])
        {
            largest = l;
        }
        if (r < size && a[r] > a[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(&a[i], &a[largest]);
            heapify(a, size, largest);
        }
    }
}

void insert(int a[], int x)
{
    int i;
    if (size == 0)
    {
        a[0] = x;
        size++;
    }
    else
    {
        a[size] = x;
        size++;
        for (i = (size / 2) - 1; i >= 0; i--)
        {
            heapify(a, size, i);
        }
    }
}

void delete (int a[], int x)
{
    int i;
    if (size == 0)
    {
        printf("no element present ");
        return;
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            if (a[i] == x)
            {
                break;
            }
        }
        swap(&a[i], &a[size - 1]);
        size--;
        for (i = (size / 2) - 1; i >= 0; i--)
        {
            heapify(a, size, i);
        }
    }
}

void heap_sort(int a[], int size)
{
    int i;
    for (i = (size - 1); i >= 1; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
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

int extract_max(int a[])
{
    int i;
    if (size == 1)
    {
        size--;
        return a[0];
    }
    swap(&a[0], &a[size - 1]);
    size--;
    for (i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(a, size, i);
    }
    return a[size];
}

int main()
{
    int n;
    printf("enter number of element :");
    scanf("%d", &n);
    int a[n], x;
    printf("enter number :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(a, x);
    }
    printf("max heap :");
    print_array(a, n);
    // delete(a,5);
    print_array(a, size);
    printf("%d \n", extract_max(a));
    print_array(a, size);
    // heap_sort(a, size);
    // print_array(a, size);
}