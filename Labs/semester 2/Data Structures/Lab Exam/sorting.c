#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{

    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int partition(int arr[], int l, int u)
{
    int temp = arr[l];
    int i = l + 1, j = u;
    do
    {
        while (arr[i] < temp)
        {
            i++;
        }
        while (arr[j] > temp)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }

    } while (i < j);

    swap(&arr[l], &arr[j]);
    return j;
}

void quicksort(int arr[], int lowerbound, int upperbound)
{
    if (lowerbound < upperbound)
    {
        int part = partition(arr, lowerbound, upperbound);
        quicksort(arr, lowerbound, part - 1);
        quicksort(arr, part + 1, upperbound);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m-l + 1;
    int n2 = r - m;
    int k = l, i , j ;
    int L[n1], M[n2];

    for ( i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for ( j = 0; j < n2; j++)
    {
        M[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = M[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = M[j++];
    }
}
void mergesort(int arr[],int l,int r){
    if (l<r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    // insertion_sort(arr, n);
    // quicksort(arr, 0, n - 1);
    mergesort(arr, 0, n - 1);
    display(arr, n);

    return 0;
}