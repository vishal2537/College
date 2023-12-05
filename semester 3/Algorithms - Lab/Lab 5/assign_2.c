#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    // (*a) = (*a) ^ (*b); 
    // (*b) = (*a) ^ (*b);
    // (*a) = (*a) ^ (*b);
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] > pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("\nPlease enter the number of cupcakes:  ");
    scanf("%d", &n);

    int a[n];
    printf("\nRespective calorie counts of each cupcake:    ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n);
    
    int result = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        result += (pow(2, j) * a[i]);
        j++;
    }

    printf("\nMarc should walk atleast : %d  miles.", result);
    return 0;
}