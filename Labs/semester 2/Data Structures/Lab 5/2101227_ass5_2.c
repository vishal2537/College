#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int arr[MAX];
int front = -1;
int rear = -1;
int size = 10;

int stretchdeque()
{
    if (rear < front)
    {
        int i = size - 1;
        while (i>= front)
        {
            arr[i + 5] = arr[i];
            i--;
        }
        front = front + 5;
    }
    size = size + 5;
    printf("\nsize is increased !! \nnew size is : %d\n",size);
}

int reducedeque()
{
    if (front > rear)
    {
        int p = front;
        while (p < size)
        {
            arr[p - 5] = arr[p];
            p++;
        }
        front = front - 5;
    }
    else if (front > 1)
    {
        int i = size - 5, j = 0;
        while (i <= rear)
        {
            arr[j] = arr[i];
            i++;
            j++;
        }
        rear = i - 1;
    }
    size = size - 5;
    printf("size is decreased !! \nnew size is : %d\n",size);
}

int insertfront(int x)
{
    if (!((rear + 1) % size == front))
    {
        if (rear == -1 && front == -1)
            front = rear = size - 1;
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front = front - 1;
        }
        arr[front] = x;
    }
    else if (size < 100)
    {
        stretchdeque();
        insertfront(x);
    }
    else
        printf("deque is full\n");
}

int insertrear(int x)
{
    if (!((rear + 1) % size == front))            
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = x;
    }
    else if (size < 100)
    {
        stretchdeque();
        insertrear(x);
    }
    else
        printf("deque is full\n");
}

int ecount()
{
    if (!(rear == -1 && front == -1))
    {
        int p = front, count = 1;
        while (p != rear)
        {
            count++;
            p = (p + 1) % size;
        }
        count++;
        return count;
    }
    else
        return 0;
}

int deletefront()
{
    if (ecount() == size - 5 && size > 10)
    {
        reducedeque();
        deletefront();
    }
    else if (!(front == -1 && rear == -1))
    {
        int x = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
            front = (front + 1) % size;
        printf("dequed data : %d\n", x);
        return x;
    }
    else
    {
        printf("queue is empty\n");
    }
}

int deleterear()
{
    if (ecount() == size - 5 && size > 10)
    {
        reducedeque();
        deleterear();
    }
    else if (!(front == -1 && rear == -1))
    {
        int x = arr[rear];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
        printf("dequeue data : %d\n", x);
        return x;
    }
    else
        printf("queue is empty\n");
}

void display()
{
    if (!(front == -1 && rear == -1))
    {
        int p = front;
        while (p != rear)
        {
            printf("%d ", arr[p]);
            p = (p + 1) % size;
        }
        printf("%d ", arr[p]);
    }
    else
        printf("queue is empty\n");
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nenter one of following options: \n1: Insert front       2: Insert rear      3: Delete front     4: Delete Rear      5: Display      6: stretchDequeue        7: EXIT\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int x;
            printf("Enter data : \n");
            scanf("%d", &x);
            insertfront(x);
            display();
        }
        else if (ch == 2)
        {
            int x;
            printf("Enter data : \n");
            scanf("%d", &x);
            insertrear(x);
            display();
        }
        if (ch == 3)
        {
            deletefront();
            display();
        }
        else if (ch == 4)
        {
            deleterear();
            display();
        }
        else if (ch == 5)
        {
            display();
        }
        else if (ch == 6)
        {
            stretchdeque();
        }
        else if (ch == 7)
        {
            return 0;
        }
    }
}