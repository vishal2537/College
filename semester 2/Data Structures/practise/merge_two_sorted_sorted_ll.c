#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *r;

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
void create1(int b[], int n)
{
    struct node *p, *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = b[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = b[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void display(struct node *q)
{
    struct node *p = q;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void merge(struct node *p, struct node *q)
{
    struct node *last;
    if (p->data < q->data)
    {
        r = last = p;
        p = p->next;
        r->next = NULL;
    }
    else
    {
        r = last = q;
        q = q->next;
        r->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
    {
        last->next = q;
    }
}

int main()
{
    int n1;
    printf("enter n1: ");
    scanf("%d", &n1);

    int a[n1];
    printf("enter element : ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    create(a, n1);

    int n2;
    printf("enter n2: ");
    scanf("%d", &n2);

    int b[n2];
    printf("enter element : ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }
    create1(b, n2);

    display(first);
    display(second);

    merge(first, second);

    display(r);

    return 0;
}
