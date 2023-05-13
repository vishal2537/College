#include <stdio.h>
#include <stdlib.h>
int size = 0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int size, int i)
{
    if (size == 1)
    {
        printf("only one element present");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && arr[l] > arr[largest])
        {
            largest = l;
        }
        if (r < size && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, size, largest);
        }
    }
}

void insert(int a[], int x)
{
    if (size == 0)
    {
        a[0] = x;
        size = size + 1;
    }
    else
    {
        // printf("elemnt aya");
        a[size] = x;
        size++;
        for (int i = (size / 2) - 1; i >= 0; i--)
        {
            heapify(a, size, i);
        }
    }
}

void delete (int a[], int x)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (x == a[i])
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
    int a[n], x;
    printf("enter number :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(a, x);
    }
    // print_array(a, n);
    printf("max heap :");
    print_array(a, n);
    // printf("hel");
    delete(a,5);
    // printf("hel");
    print_array(a, size);
    // printf("hel");

}