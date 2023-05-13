#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int data)
{

    if (q->front == (q->rear + 1) % q->size)
    {
        printf("queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = data;
    }
}

int dequeue()
{
    struct queue *q;
    int x = -1;
    if (q->front == q->rear)
        printf("empty\n");

    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

void display(struct queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i = (i + 1) % q.size)
    {
        printf("%d ", q.Q[i]);
    }
}

void arrayBata(struct queue q){
    int i;
    for(i=0;i<=q.size;i++){
        printf("%d ", q.Q[i]);
    }
}

int main()
{
    int n;
    printf("enter size of array : ");
    scanf("%d", &n);
    struct queue q;
    create(&q, n);
    printf("enter the data : ");
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(&q, x);
    }
    arrayBata(q);
    // display(q);
    int ch;
    printf("enter choice : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        dequeue();
        break;

    case 2:
        display(q);
        break;

    case 3:
        printf("enter data :");
        scanf("%d", &x);
        enqueue(&q, x);
        arrayBata(q);
        break;

    default:
        break;
    }

    return 0;
}
