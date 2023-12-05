#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void create(int a[], int n)
{
    int i;
    struct node *p, *last;

    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void removeduplicate(struct node *w)
{
    struct node*p=first;
    struct node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

int main()
{
    int n;
    printf("enter number of elemnt in ll : ");
    scanf("%d", &n);
    int a[n];

    printf("enter element of linked list : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    create(a, n);

    display(first);

    printf("\n************************************************\n");

    removeduplicate(first);

    display(first);

    return 0;
}