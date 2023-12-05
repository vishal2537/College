#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *tail = NULL;

void insert_first(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = first;
    first = t;
    if (tail == NULL)
    {
        tail = t;
    }
}
int delete_first()
{
    int x = first->data;
    first = first->next;
    return x;
}
void insert_last(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    tail->next = t;
    tail = t;
    if (first == NULL)
    {
        first = t;
    }
}
int delete_last()
{
    int x = tail->data;
    struct node *last = first;
    while ((last->next)->next != NULL)
    {
        last = last->next;
    }
    last->next = NULL;
    tail = last;
    return x;
}

void swap_ends()
{
    int x = delete_first();
    int y = delete_last();
    insert_first(y);
    insert_last(x);
}
void shift_left(int k)
{

    int x;
    for (int i = 0; i < k; i++)
    {
        x = delete_first();
        insert_last(x);
    }
}
void display()
{
    struct node *p = first;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int x;
    printf("for inserting first\n");
    printf("Enter data:\n");
    scanf("%d", &x);
    insert_first(x);
    display();
    printf("\n");

    printf("for inserting last");

    printf("Enter data:\n");
    scanf("%d", &x);
    insert_last(x);
    display();
    printf("\n");

    printf("Enter data:\n");
    scanf("%d", &x);
    insert_last(x);
    display();
    printf("\n");

    printf("Enter data:\n");
    scanf("%d", &x);
    insert_last(x);
    display();
    printf("\n");

    printf("Enter data:\n");
    scanf("%d", &x);
    insert_last(x);

    display();
    printf("\n");

    printf("list after deleting last element\n");
    delete_last();
    display();
    printf("\n");

    printf("list after deleting first element\n");
    delete_first();
    display();
    printf("\n");


    printf("list after swapping\n");
    swap_ends();
    display();
    printf("\n");

    printf("Shift left by:\n");
    scanf("%d", &x);
    shift_left(x);
    display();

    return 0;
}