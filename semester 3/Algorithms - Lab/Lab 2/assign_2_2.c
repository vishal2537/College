#include <stdio.h>

void print_array(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("number of element in array  :");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int max_sum = 0;
    int f, l;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (max_sum <= sum)
            {
                max_sum = sum;
                f = i;
                l = j;
            }
            // printf("%d ",a[j]);
        }
    }

    printf("\nmaximum sum of subarray = %d", max_sum);
    printf("\nsubarray : ");
    print_array(a, f, l);

    return 0;
}