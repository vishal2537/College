#include <stdio.h>
#include <stdlib.h>

#define size 5
int front = -1;
int rear = -1;
int q[size];

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        q[rear] = x;
    }

    else if ((rear + 1) % size == front)
    {
        printf("queue is overflow\n");
    }

    else
    {
        rear = (rear + 1) % size;
        q[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }

    else if (front == rear)
    {
        printf("dequeued element : %d", q[front]);
        front = rear = -1;
    }
    else
    {
        printf("dequeued element : %d", q[front]);
        front = (front + 1) % size;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        while (i < rear)
        {
            printf("%d ", q[i]);
            i = (i + 1) % size;
        }
        printf("%d", q[i]);
    }
}

int main()
{
    int choice = 1, x;

    while (1)
    {
        printf("\n Press 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the element");
        printf("\nEnter your choice : \n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter the element which is to be inserted : ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
        }
    }
    return 0;
}