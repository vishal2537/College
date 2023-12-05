#include <stdio.h>
#include <stdlib.h>

struct deque
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct deque *q, int n)
{
    q->front = q->rear = -1;
    q->size = n;
    q->Q = (int *)malloc(q->size * (sizeof(int)));
}

void insertfront(struct deque *q, int x)
{
    if ((q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear - 1))
    {
        printf("deque is full\n");
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->Q[q->front] = x;
    }
    else if (q->front == 0)
    {
        q->front = q->size - 1;
        q->Q[q->front] = x;
    }
    else
    {
        q->front = q->front - 1;
        q->Q[q->front] = x;
    }
}

void insertrear(struct deque *q, int x)
{
    if ((q->front == 0 && q->rear == q->size - 1) || q->front == q->rear + 1)
    {
        printf("deque is overflow\n");
    }
    else if ((q->front == -1) && (q->rear == -1))
    {
        q->rear = 0;
        q->Q[q->rear] = x;
    }
    else if (q->rear == q->size - 1)
    {
        q->rear = 0;
        q->Q[q->rear] = x;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int deletefront(struct deque *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("deque is underflow\n");
    }
    else if (q->front == q->rear)
    {
        printf("%d", q->Q[q->front]);
        q->front = q->rear = -1;
    }
    else if (q->front == q->size - 1)
    {
        printf("%d", q->Q[q->front]);
    }
    else
    {
        printf("%d", q->Q[q->front]);
        q->front = q->front + 1;
    }
}

int deleterear(struct deque *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("qeque is underflow\n");
    }
    else if (q->front == q->rear)
    {
        printf("%d", q->Q[q->rear]);
        q->front = q->rear = -1;
    }
    else if (q->rear == 0)
    {
        printf("%d", q->Q[q->rear]);
        q->rear = q->size - 1;
    }
    else
    {
        printf("%d", q->Q[q->rear]);
        q->rear--;
    }
}

void display(struct deque *q)
{
    int i = q->front;
    i = (i + 1) % q->size;
    while (i != q->rear)
    {
        printf("%d ", q->Q[i]);
        i = (i + 1) % q->size;
    }
    printf(" %d ", q->Q[q->rear]);
}

int main()
{
    struct deque q;
    int n;
    printf("enter size of queue : ");
    scanf("%d", &n);

    create(&q, n);

    int ch, x;
    while (1)
    {
        printf("\n1.intsertfront\n");
        printf("2.intsertrear\n");
        printf("3.deletefront\n");
        printf("4.deleterear\n");
        printf("5.display\n");
        printf("enter choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("enter data : ");
            scanf("%d", &x);
            insertfront(&q, x);
        }
        else if (ch == 2)
        {
            printf("enter data : ");
            scanf("%d", &x);
            insertrear(&q, x);
        }
        else if (ch == 3)
        {
            deletefront(&q);
        }
        else if (ch == 4)
        {
            deleterear(&q);
        }
        else if (ch == 5)
        {
            display(&q);
        }
    }

    return 0;
}