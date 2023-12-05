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

void bubblesort(int a[], int n)
{
    int temp, is_Sorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            is_Sorted = 1;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                is_Sorted = 0;
            }
            if (is_Sorted)
            {
                return;
            }
        }
    }
}

int main()
{
    int n;
    printf("enter the number of element :");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    print_array(a, n);
    bubblesort(a, n);
    print_array(a, n);
    return 0;
}
