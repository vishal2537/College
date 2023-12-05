#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int A[SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        A[rear] = data;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        A[rear] = data;
    }
    return;
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("array is empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
    return;
}

void queueSize()
{
    int x = front;
    int count = 0;
    while (((x) % SIZE) != rear)
    {
        count++;
        x++;
    }
    count++;
    printf("the size is : %d \n", count);
}

void display()
{
    int f = front;
    while (((f) % SIZE) != rear)
    {
        printf("%d ", A[f]);
        f++;
    }
    printf("%d \n", A[rear]);
}

int main()
{
    int ch, p;
    while (1)
    {
        printf("Enter your choice\n");
        printf("0. Exit       1. enqueue        2. dequeue        3. queueSize          4. Display\n");
        scanf("%d", &ch);
        if (ch == 0)
        {
            return 0;
        }
        else if (ch == 1)
        {
            printf("Enter element : ");
            scanf("%d", &p);
            enqueue(p);
            display();
        }
        else if (ch == 2)
        {
            dequeue();
            display();
        }
        else if (ch == 3)
        {
            queueSize();
        }
        else if (ch == 4)
        {
            display();
        }
    }
    return 0;
}