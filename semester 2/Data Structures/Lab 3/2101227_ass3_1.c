#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
} *Top = NULL;

int isEmpty()
{
    if (Top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(int x)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = x;
    temp->next = Top;
    Top = temp;
}
int pop()
{
    if (!isEmpty())
    {
        int x = Top->data;
        Top = Top->next;
        return x;
    }
    else
        printf("stack is empty\n");
}
int top()
{

    return Top->data;
}

int buildstack()
{
    printf("enter no of elements\n");
    int n;
    scanf("%d", &n);
    while (n--)
    {
        printf("enter element : ");
        int x;
        scanf("%d", &x);
        push(x);
    }
}

void display()
{
    struct stack *p;
    p = Top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    buildstack();

    while (1)
    {
        printf("1.push() 2.pop() 3.display() 4.top 5.isEmpty() \nChoose your input:\n");

        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            int x;
            printf("Enter Data:\n");
            scanf("%d", &x);
            push(x);
            display();
        }
        else if (ch == 2)
        {
            int x = pop();
            if (x == -1)
            {
                printf("Empty stack\n");
            }
            else
            {
                printf("poped element : %d\n", x);
            }
            display();
        }
        else if (ch == 3)
        {
            display();
        }
        else if (ch == 4)
        {
            if (isEmpty() == 1)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                int x = top();
                printf("top element is : %d \n", x);
            }
        }
        else if (ch == 5)
        {
            if (isEmpty() == 1)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is not Empty\n");
            }
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
}