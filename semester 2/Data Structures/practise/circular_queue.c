#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct queue *q, int n)
{
    q->front = q->rear = -1;
    q->size = n;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int data)
{
    if (q->front == (q->rear + 1) % q->size)
    {
        printf("queue overflow\n");
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->Q[q->rear] = data;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct queue *q)
{
    int x = -1;
    if (q->front == -1 && q->rear == -1)
    {
        printf("queue is underflow\n");
        return -1;
    }
    else if (q->front == q->rear && q->front!=-1)
    {
        x = q->Q[q->front];
        q->front = q->rear = -1;
        return x;
    }
    else
    {
        x = q->Q[q->front];
        q->front = (q->front + 1) % q->size;
        return x;
    }
}

void display(struct queue *q)
{
    int i = q->front;
    while (i !=q->rear)
    {
        printf("%d ", q->Q[i]);
        i = (i + 1) % q->size;
    }
    printf("%d \n", q->Q[i]);
}

int main()
{
    struct queue q;
    int n;
    printf("enter size of queue : ");
    scanf("%d", &n);
    create(&q, n);
    int choice, x;
    while (1)
    {
        printf("\nPress 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the element");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter the element which is to be inserted : ");
            scanf("%d", &x);
            enqueue(&q, x);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
        }
    }

    return 0;
}
