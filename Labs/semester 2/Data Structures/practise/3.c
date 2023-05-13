#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int a[], int n)
{
    struct node *p, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void deletecontinuousnode(struct node *w, int k)
{
    struct node *p = first;
    struct node *q,*t;
    while (p->next!= NULL)
    {
        int sum =p->data;
        q=p->next;
        if (sum == k)
            p = p->next;
        while (q != NULL)
        {
            sum = sum + q->data;
            if (sum == k)
            {
                p->next = q->next;
            }
            q = q->next;
        }
        p = p->next;
        if (p != NULL)
        {
            q = p->next;
        }
    }
}

int main()
{
    int n;
    printf("enter the number of element in ll : ");
    scanf("%d", &n);

    int a[n];
    printf("enter number : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int k;
    printf("enter value of k : ");
    scanf("%d", &k);

    create(a, n);

    display(first);
    printf("\n");

    deletecontinuousnode(first, k);
    display(first);
    printf("\n");

    return 0;
}