#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void create(int a[], int n)
{
    struct node *p, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    int i;
    for (i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void continuousnode(struct node *w, int k)
{
    struct node *p = first;
    struct node *q=NULL;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data + q->data == k)
            printf("%d %d\n",p->data,q->data);
            q = q->next;
        }
        p = p->next;
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

    continuousnode(first, k);

    // display(first);

    printf("\n");
}