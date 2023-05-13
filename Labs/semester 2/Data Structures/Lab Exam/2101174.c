#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{

    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(&arr[smallest], &arr[i]);
        heapify(arr, n, smallest);
    }
}

void createheap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

int extract_min(int arr[], int n)
{

    int temp = arr[0];
    arr[0] = arr[n];
    int i = 0;
    int j = 1;
    while (j < n - 1)
    {
        if (arr[i] > arr[j] && arr[j]<arr[j+1])
        {
            swap(&arr[i], &arr[j]);
            i = j;
            j = j * 2;
        }
        else if (arr[i] > arr[j + 1])
        {
            j = j + 1;
            swap(&arr[i], &arr[j]);
            i = j;
            j = j * 2;
        }

        else
        {
            break;
        }
    }
    arr[n] = temp;
    return temp;
}
void print(int arr[], int n)
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
    printf("Enter the size of array \n");
    scanf("%d", &n);
    int x = n;

    int arr[n];
    printf("Enter data\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    createheap(arr, n);
    while (1)
    {
        printf("1 - Printheap()\n");
        printf("2 - Extract_min()\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            print(arr, n);
        }
        else if (choice == 2)
        {
            printf("The minimum element is : %d\n", extract_min(arr, x - 1));
            x--;
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
