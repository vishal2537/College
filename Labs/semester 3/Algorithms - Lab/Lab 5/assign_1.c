#include <stdio.h>
#include <stdlib.h>

struct coin
{
    int coin;
    int frequency;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
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
    printf("enter denominations : ");
    scanf("%d", &n);

    int co[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &co[i]);
    }

    int t_money;
    scanf("%d", &t_money);
    quickSort(co, 0, n );
    struct coin freq[n];
    int y = 0;
    int i = n;
    while (i >= 0 && t_money > 0)
    {
        if (t_money - co[i] >= 0)
        {
            int q = t_money / co[i];
            t_money -= (co[i] * q);
            freq[y].coin = co[i];
            freq[y].frequency = q;
            y++;
        }
        else
        {
            i--;
        }
    }
    for (i = 0; i < y; i++)
    {
        if (t_money == 0)
        {
            printf(" {  %d -->  %d  }\n",freq[i].coin,freq[i].frequency);
        }
        else
        {
            printf("!! insufficient coins !!");
        }
    }

    return 0;
}