#include <stdio.h>
#include <stdlib.h>

struct subarray_max
{
    int start;
    int end;
    int sum;
};

void print_array(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

struct subarray_max *max_crossing_sum(int a[], int l, int mid, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    int l_start;
    for (int i = mid; i >= l; i--)
    {
        sum += a[i];
        if (left_sum < sum)
        {
            left_sum = sum;
            l_start = i;
        }
    }
    int right_sum = INT_MIN;
    int r_end;
    sum = 0;
    for (int i = mid+1; i <= h; i++)
    {
        sum += a[i];
        if (right_sum < sum)
        {
            right_sum = sum;
            r_end = i;
        }
    }
    int x=left_sum+right_sum;
    struct subarray_max *p = (struct subarray_max *)malloc(sizeof(struct subarray_max));
    p->sum = x;
    p->start = l_start;
    p->end = r_end;
    return p;
}

struct subarray_max *max_subarray_sum(int a[], int l, int h)
{
    if (l == h)
    {
        struct subarray_max *p = (struct subarray_max *)malloc(sizeof(struct subarray_max));
        p->sum = a[l];
        p->start = l;
        p->end = h;
        return p;
    }
    else
    {
        int mid = (l + h) / 2;
        struct subarray_max *m = (struct subarray_max *)malloc(sizeof(struct subarray_max));
        m = max_crossing_sum(a, l, mid, h);

        struct subarray_max *l1 = (struct subarray_max *)malloc(sizeof(struct subarray_max));
        l1 = max_subarray_sum(a, l, mid);

        struct subarray_max *r = (struct subarray_max *)malloc(sizeof(struct subarray_max));
        r = max_subarray_sum(a, mid + 1, h);

        if (l1->sum >= r->sum && l1->sum >= m->sum)
        {
            return l1;
        }
        else if (r->sum >= m->sum && r->sum >= l1->sum)
        {
            return r;
        }
        else if (m->sum >= l1->sum && m->sum >= r->sum)
        {
            return m;
        }
    }
}

int main()
{
    int n;
    printf("enter number of you want to enter : ");
    scanf("%d", &n);
    int a[n];
    printf("enter numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    struct subarray_max *x = max_subarray_sum(a, 0, n - 1);
    printf("max_sum: %d ", x->sum);
    printf("\nsubarray :");
    print_array(a, x->start, x->end);
    return 0;
}

// -6 15 -4 -3 6 3 -9 1 -7 7