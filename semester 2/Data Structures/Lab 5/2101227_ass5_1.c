#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    return newnode;
}

void insertFront(int x)
{
    struct node *temp = createnode(x);
    if (front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}
void insertRear(int x)
{
    struct node *temp = createnode(x);
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }
}

void deleteFront()
{
    if (front == NULL)
    {
        return;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        front->prev = NULL;
        free(temp);
    }
}

void deleteRear()
{
    if (rear == NULL)
    {
        return;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        struct node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        free(temp);
    }
}

int isempty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

void printElements()
{
    struct node *temp;
    temp = front;
    while (temp != rear)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", rear->data);
    printf("\n");
}

int main()
{
    while (1)
    {
        printf("1.insertFront()     2.deleteFront()       3.printElements()      4.insertRear()      5.deleteRear()\nchoose your input:\n");

        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            int a;
            printf("enter data : ");
            scanf("%d", &a);
            insertFront(a);
        }
        else if (x == 2)
        {
            deleteFront();
            if (isempty())
            {
                printf("queue is empty !!\n");
            }
        }
        else if (x == 3)
        {
            printElements();
        }
        else if (x == 4)
        {
            int a;
            printf("enter data : ");
            scanf("%d", &a);
            insertRear(a);
        }
        else if (x == 5)
        {
            deleteRear();
            if (isempty())
            {
                printf("queue is empty !!\n");
            }
        }
        else
        {
            printf("invalid input\n");
        }
    }
    return 0;
}