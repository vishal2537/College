#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

void create(int a[], int n)
{
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = NULL;
    head->prev = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void deleteContinuosNode(int k)
{
    struct node *p = NULL, *q = NULL;
    p = head;
    int sum = 0, flag = 0;
    while (p->next != NULL)
    {
        sum = p->data;
        if (sum == k)
        {
            if (p == head)
            {
                head = p->next;
                head->prev = NULL;
                p = p->next;
            }
            else
            {
                (p->prev)->next = p->next;
                (p->next)->prev = p->prev;
                p = p->next;
            }
            // continue;
        }
        q = p->next;
        flag = 0;
        while (q != NULL)
        {
            sum += q->data;
            if (sum == k)
            {
                flag = 1;
                break;
            }
            q = q->next;
        }
        if (flag)
        {
            if (p == head)
            {
                head = q->next;
                head->prev = NULL;
            }
            else
            {
                (p->prev)->next = q->next;
                (q->next)->prev = p->prev;
            }
        }
        if (flag)
        {
            p = q->next;
        }
        else
        {
            p = p->next;
        }
    }
}

void display()
{
    struct node *t;
    t = head;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the no of nodes in linked list: \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter data of nodes\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    create(a, n);
    printf("Enter value of k: \n");
    int k;
    scanf("%d", &k);
    printf("Öriginal List: \n");
    display();
    deleteContinuosNode(k);
    printf("New List: \n");
    display();
    return 0;
}