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
    q->front = -1;
    q->rear = -1;
    q->Q = (int *)malloc(q->size * (sizeof(int)));
}

int insertfirst(struct queue *p, int data)
{
    if (p->front == -1 && p->rear == -1)
    {
        p->front++;
        p->rear++;
        p->Q[p->front] = data;
    }
    else if ((p->rear + 1) % p->size == p->front)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        p->front = (p->size + p->front - 1) % (p->size);
        p->Q[p->front] = data;
    }
}

int insertlast(struct queue *p, int data)
{
    if (p->front == -1 && p->rear == -1)
    {
        p->front++;
        p->rear++;
        p->Q[p->rear] = data;
    }
    else if ((p->rear + 1) % p->size == p->front)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        p->rear = (p->rear + 1) % (p->size);
        p->Q[p->rear] = data;
    }
}

int deletefirst(struct queue *p)
{
    int x = -1;
    if (p->front == -1 && p->rear == -1)
    {
        printf("The Queue is Empty!\n");
    }
    else if (p->front == p->rear)
    {
        x = p->Q[p->front];
        p->front = p->rear = -1;
    }
    else
    {
        x = p->Q[p->front];
        p->front = (p->front + 1) % (p->size);
    }
    return x;
}

int deletelast(struct queue *p)
{
    int x = -1;
    if (p->front == -1 && p->rear == -1)
    {
        printf("The Queue is Empty!\n");
    }
    else if (p->front == p->rear)
    {
        x = p->Q[p->front];
        p->front = p->rear = -1;
    }
    else
    {
        x = p->Q[p->rear];
        p->rear = (p->rear - 1) % (p->size);
    }
    return x;
}

void display(struct queue *p)
{
    int i = p->front;
    printf("The queue is :\n");
    while (i != p->rear)
    {
        printf("%d ", p->Q[i]);
        i = (i + 1) % p->size;
    }
    if (p->rear != -1)
    {
        printf("%d\n", p->Q[p->rear]);
    }
}

int main()
{
    int n;
    printf("enter size of queue : ");
    scanf("%d", &n);

    struct queue q;
    create(&q, n);
    int ch;
    while (1)
    {
        printf("\n1.insertfront()");
        printf("\n2.insertlast() ");
        printf("\n3.deletefront() ");
        printf("\n4.deletelast() ");
        printf("\n5.display() ");
        printf("\nenter choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("enter data : ");
            scanf("%d", &n);
            insertfirst(&q, n);
        }
        else if (ch == 2)
        {
            printf("enter data : ");
            scanf("%d", &n);
            insertlast(&q, n);
        }
        else if (ch == 3)
        {
            deletefirst(&q);
        }
        else if (ch == 4)
        {
            deletelast(&q);
        }
        else if (ch == 5)
        {
            display(&q);
        }

    }
    
    return 0;
}






// deque me
// insert front me front=(front +size -1)%size krke insert kartyew hai
// insert rear me rear=(rear+1)%size krke insert karte hai
// delete front me front =(front+1)%size karke dekete karte hai
// delete rear me rear=(rear-1)%size karke delete karte hai
// print karne  ke liye front se start karte hai jb tk rear-1 ke barabar ni hota tab tak praint karte hai
// aur last me fornt = rear wale element ko print karte hain