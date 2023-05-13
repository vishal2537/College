#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int a[], int n)
{
    int key, j;
    // loop for pass
    for (int i = 0; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;
        // loop for each pass
        while (j>=0 && a[j] > key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key; 
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
    insertion_sort(a, n);
    print_array(a, n);

    return 0;
}