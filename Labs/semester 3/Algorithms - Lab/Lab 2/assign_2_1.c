#include <stdio.h>
#include<stdlib.h>

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
    int sum = 0, max_sum = INT_MIN, f, l;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            if (sum >= max_sum)
            {
                max_sum = sum;
                f = i;
                l = j;
            }
        }
    }

    printf("maximum sum of subarray = %d", max_sum);
    printf("\nsubarray : ");
    print_array(a, f, l);

    return 0;
}