#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int mid1, int mid, int mid2, int h)
{
    int a1_size = mid1 - l + 1;
    int a2_size = mid - mid1;
    int a3_size = mid2 - mid;
    int a4_size = h - mid2;

    int a1[a1_size+1], a2[a2_size+1], a3[a3_size+1], a4[a4_size+1];
    a1[a1_size] = a2[a2_size] = a3[a3_size] = a4[a4_size] = INT_MAX;

    int i, n = l;
    for (i = 0; i < a1_size; i++)
    {
        a1[i] = a[n++];
    } 
    for (i = 0; i < a2_size; i++)
    {
        a2[i] = a[n++];
    }
    for (i = 0; i < a3_size; i++)
    {
        a3[i] = a[n++];
    }
    for (i = 0; i < a4_size; i++)
    {
        a4[i] = a[n++];
    }

    int x = l;
    int j, k, m;
    i = j = k = m = 0;
    while (x <= h)
    {
        if (a1[i] <= a2[j] && a1[i] <= a3[k] && a1[i] <= a4[m])
        {
            a[x++] = a1[i++];
            // printf("//1 :  %d ---> ",a[x]);
        }
        else if (a2[j] <= a1[i] && a2[j] <= a3[k] && a2[j] <= a4[m])
        {
            a[x++] = a2[j++];
            // printf("//2 :  %d ---> ",a[x]);
        }
        else if (a3[k] <= a1[i] && a3[k] <= a2[j] && a3[k] <= a4[m])
        {
            a[x++] = a3[k++];
            // printf("//3 :  %d ---> ",a[x]);
        }
        else
        {
            a[x++] = a4[m++];
            // printf("//4 :  %d ---> ",a[x]);
        }
    }
    printf("\n\nlow: %d, mid1: %d, mid: %d, mid2: %d, high: %d \n\n", l, mid1, mid, mid2, h);
    for (int i = l; i <=h ; i++)
    {
        printf("-- %d -- ",a[i]);
    }
    printf("\n");
}

void merge_sort(int a[], int l, int h)
{
    int mid1;
    int mid2;
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        mid1 = (l + mid) / 2;
        mid2 = (mid + h) / 2;
        merge_sort(a, l, mid1);
        merge_sort(a, mid1 + 1, mid);
        merge_sort(a, mid + 1, mid2);
        merge_sort(a, mid2 + 1, h);

        merge(a, l, mid1, mid, mid2, h);
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
    printf("\ngiven array : ");
    print_array(a, n);
    merge_sort(a, 0, n - 1);
    printf("\nsorted array : ");
    print_array(a, n);

    return 0;
}