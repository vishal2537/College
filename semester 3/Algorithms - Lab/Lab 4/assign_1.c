#include <stdio.h>
#include <stdlib.h>

struct job
{
    int start_time;
    int finish_time;
};

void swap(struct job *a, struct job *b)
{
    struct job t = *a;
    *a = *b;
    *b = t;
}

int partition_y(struct job p[], int low, int high)
{
    int pivot = p[high].finish_time;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (p[j].finish_time < pivot)
        {
            i++;
            swap(&p[i], &p[j]);
        }
    }
    swap(&p[i + 1], &p[high]);
    return (i + 1);
}
void quickSort_y(struct job p[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_y(p, low, high);
        quickSort_y(p, low, pi - 1);
        quickSort_y(p, pi + 1, high);
    }
}

int partition_x(struct job p[], int low, int high)
{
    int pivot = p[high].start_time;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (p[j].start_time < pivot)
        {
            i++;
            swap(&p[i], &p[j]);
        }
    }
    swap(&p[i + 1], &p[high]);
    return (i + 1);
}
void quickSort_x(struct job p[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_x(p, low, high);
        quickSort_x(p, low, pi - 1);
        quickSort_x(p, pi + 1, high);
    }
}

int x = 0;
struct job jobs_cardi[100];
void max_cardinality(struct job jobs[], int n)
{
    quickSort_y(jobs, 0, n);
    for (int i = 1; i <= n; i++)
    {
        jobs_cardi[x++] = jobs[i];
        int j = i + 1;
        while (j <= n && jobs[j].start_time < jobs[i].finish_time)
        {
            j++;
        }
        i = j - 1;
    }
}

void conflicts(struct job jobs[], int a[], int n)
{
    quickSort_x(jobs, 0, n);
    for (int i = 1; i <= n; i++)
    {
        int j = i + 1;
        while (j <= n && (jobs[i].finish_time > jobs[j].start_time))
        {
            a[i] += 1;
            a[j] += 1;
            j++;
        }
    }
}

int main()
{
    int n;
    printf("enter number of jobs : ");
    scanf("%d", &n);

    struct job jobs[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter start_time of job[%d] : ", i + 1);
        scanf("%d", &jobs[i].start_time);
        printf("enter finish_time of job[%d] : ", i + 1);
        scanf("%d", &jobs[i].finish_time);
    }
    printf("\njobs input :\n");
    for (int i = 0; i < n; i++)
    {
        printf("    { %d  %d }  \n", jobs[i].start_time, jobs[i].finish_time);
    }
    max_cardinality(jobs, n);
    printf("\nthe set of jobs with maximum cardinality which can be scheduled : \n");
    for (int i = 0; i < x; i++)
    {
        printf("{ %d ", jobs_cardi[i].start_time);
        printf("%d }\n", jobs_cardi[i].finish_time);
    }

    int a[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = 0;
    }

    quickSort_x(jobs, 0, n);
    conflicts(jobs, a, n);
    printf("\njobs and conflicts : \n");
    for (int i = 1; i <= n; i++)
    {
        printf("{ %d  %d }  :  %d\n", jobs[i].start_time, jobs[i].finish_time, a[i]);
    }

    int i_max_conflict = 1;
    int i_min_conflict = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i_max_conflict])
        {
            i_max_conflict = i;
        }
        if (a[i] < a[i_min_conflict])
        {
            i_min_conflict = i;
        }
    }
    // int max[n];
    // int min[n];
    // int y = 0, z = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i] == a[i_max_conflict])
    //     {
    //         max[y++] = i;
    //     }
    //     if (a[i] == a[i_min_conflict])
    //     {
    //         min[z++] = i;
    //     }
    // }

    printf("\nJob with maximum conflicts  : { %d  %d }  :  %d\n", jobs[i_max_conflict].start_time, jobs[i_max_conflict].finish_time, a[i_max_conflict]);
    printf("\nJob with minimum conflicts  : { %d  %d }  :  %d\n", jobs[i_min_conflict].start_time, jobs[i_min_conflict].finish_time, a[i_min_conflict]);
    // printf("Job with maximum conflicts  : \n");
    // for (int i = 0; i < y; i++)
    // {
    //     printf("{ %d  %d }  :  %d\n", jobs[max[i]].start_time, jobs[max[i]].finish_time, a[max[i]]);
    // }
    // printf("Job with miniimum conflicts  : \n");
    // for (int i = 0; i < z; i++)
    // {
    //     printf("{ %d  %d }  :  %d\n", jobs[min[i]].start_time, jobs[min[i]].finish_time, a[min[i]]);
    // }

    return 0;
}

// 1 2 3 4 5 6 1 3 2 6
// 1 2
// 3 4
// 5 6
// 1 2: 1
// 1 3: 2
// 2 6: 3
// 3 4: 1
// 5 6: 1

// 1 9 2 6 5 10 2 5 1 3
// 1 3
// 5 10
// 1 3: 3
// 1 9: 4
// 2 5: 3
// 2 6: 4
// 5 10: 2