#include <stdio.h>
#include <stdlib.h>
#define wl 10
#define sl 5
struct queue
{
    int front;
    int rear;
    int size;
    int wa[wl];
} * wq;

struct queuenode
{
    int sa[sl];
    int front;
    int rear;
    int size;
    struct queuenode *next;
} *FRONT = NULL, *REAR = NULL;

int nodecount = 0;
struct queuenode *createqueuenode()
{
    struct queuenode *temp = (struct queuenode *)malloc(sizeof(struct queuenode));
    temp->front = temp->size = 0;
    temp->rear = sl - 1;
    temp->next = NULL;
    if (!nodecount)
    {
        FRONT = REAR = temp;
    }
    else
    {
        REAR->next = temp;
        REAR = temp;
    }
    nodecount++;
    return temp;
}

int enqueue(int data)
{
    if (wq->size != wl)
    {
        wq->rear = (wq->rear + 1) % wl;
        wq->wa[wq->rear] = data;
        wq->size++;
    }
    else
        printf("queue is full\n");
}

int dequeue()
{
    if (wq->size)
    {
        int temp = wq->wa[wq->front];
        wq->front = (wq->front + 1) % wl;
        wq->size--;
        return temp;
    }
    else
    {
        printf("queue is empty\n");
    }
}

int serviceenqueue(int data, struct queuenode *p)
{
    if (p->size < sl)
    {
        p->rear = (p->rear + 1) % sl;
        p->sa[p->rear] = data;
        p->size++;
    }
}

int servicedequeue()
{
    if (FRONT->size)
    {
        int x = FRONT->sa[FRONT->front];
        FRONT->front = (FRONT->front + 1) % sl;
        FRONT->size--;
        if (FRONT->size == 0 && nodecount > 1)
        {
            FRONT = FRONT->next;
            nodecount--;
        }
        return x;
    }
    else if (nodecount > 1)
    {
        FRONT = FRONT->next;
        nodecount--;
        servicedequeue();
    }
}

void multEnqueue(int x)
{
    if (REAR->size != sl)
    {
        serviceenqueue(x, REAR);
        printf("Element enter in service list.\n");
    }
    else if (FRONT->size != sl)
    {
        serviceenqueue(x, FRONT);
    }
    else if (wq->size != wl)
    {
        enqueue(x);
        printf("Element enter in wait list.\n");
    }
    else
    {
        struct queuenode *temp = createqueuenode();
        int i = 5;
        while (i--)
        {
            serviceenqueue(dequeue(), REAR);
        }
        enqueue(x);
        printf("new node created !!\n");
    }
}

int multDequeue()
{
    if (wq->size)
    {
        int x = servicedequeue();
        int data = dequeue();
        serviceenqueue(data, FRONT);
        printf("dequeued element : %d\n", x);
        return x;
    }
    else if (wq->size == 0)
    {
        int x = servicedequeue();
        printf("dequeued element : %d\n", x);
        return x;
    }
    else
    {
        printf("node is empty.\n");
    }
}

void servicedisplay(struct queuenode *temp)
{
    int i = temp->size, tf = temp->front;
    while (i--)
    {
        printf("%d ", temp->sa[tf]);
        tf = (tf + 1) % sl;
    }
    if (temp->size == 0)
        printf("service list is empty\n");
    printf("\n");
}

void display()
{
    int temp = wq->size, tf = wq->front;
    while (temp--)
    {
        printf("%d ", wq->wa[tf]);
        tf = (tf + 1) % wl;
    }
    if (wq->size == 0)
        printf("queue is empty");
    printf("\n");
}

int statusQueue()
{
    printf("no of node in service list= %d\n", nodecount);
    struct queuenode *temp = FRONT;
    int i = 1;
    while (i <= nodecount)
    {
        printf("node %d -> ", i++);
        servicedisplay(temp);
        temp = temp->next;
    }
    printf("wait queue -> ");
    display();
    printf("the next element will be placed in ");
    if (REAR->size != sl)
    {
        printf("service queue\n");
    }
    else if (wq->size != wl)
    {
        printf("wait queue\n");
    }
    else
    {
        printf("multQueue is full\n");
    }
}

int main()
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    temp->front = temp->size = 0;
    temp->rear = wl - 1;
    wq = temp;
    struct queuenode *servicequ = createqueuenode();
    while (1)
    {
        int t;
        printf("\n0=exit      1=multEnqueue       2=Multdequeue       3=statusQueue\n");
        printf("\nEnter your choice : \n");
        scanf("%d", &t);
        if (t == 1)
        {
            int value;
            printf("enter value to enqueue : \n");
            scanf("%d", &value);
            multEnqueue(value);
            display();
        }
        else if (t == 2)
        {
            multDequeue();
            display();
        }
        else if (t == 3)
        {
            statusQueue();
            display();
        }
        else if (t == 0)
            return 0;
    }
}