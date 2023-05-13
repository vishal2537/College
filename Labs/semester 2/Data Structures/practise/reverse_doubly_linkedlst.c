#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;

void create(int a[], int n)
{
    struct node *p, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = NULL;
    head->prev = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        p->prev = last;
        last->next = p;
        last = p;
    }
}

void display(struct node *q)
{
    struct node *p = q;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void reverse(struct node *q)
{
    struct node *p = q, *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            head = p;
    }
}

int main()
{
    int n;
    printf("enter number of element : ");
    scanf("%d", &n);

    int a[n];
    printf("enter data : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    create(a, n);
    printf("\nll is :\n");
    display(head);

    reverse(head);
    display(head);

    return 0;
}