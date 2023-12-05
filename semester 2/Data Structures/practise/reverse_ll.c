#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int a[], int n)
{
    struct node *p, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void reverse(struct node *w)
{
    struct node *p = w;
    struct node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int a[n];
    printf("enter element : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    create(a, n);
    display(head);

    reverse(head);
    display(head);
}