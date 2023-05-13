#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int findmax(int a[], int n)
{
    int max = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void count_sort(int a[], int n)
{
    int i, j, max, *c;
    max = findmax(a, n);
    c = (int*)malloc(sizeof(int) * (max + 1));
    for (int i = 0; i < max + 1; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (c[j] > 0)
        {
            a[i++] = j;
            c[j]--;
        }
        else
            j++;
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
    printf("enter the number of element :");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    print_array(a, n);
    count_sort(a, n);
    print_array(a, n);
    return 0;
}