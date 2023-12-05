#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int *s;
    int top;
};

void buildstack(struct stack *p, int n)
{
    p->size = n;
    p->s = (int *)malloc(2 * n * sizeof(int));
    p->top = -1;
}

int i = 0;
void push(struct stack *p, int data)
{
    if (p->top == p->size - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        p->top++;
        p->s[p->top] = data;
    }
    if (p->top == 0)
    {
        p->s[p->size + i] = data;
        i++;
    }
    else if (p->s[p->size + i - 1] > data)
    {
        p->s[p->size + i ] = data;
        i++;
    }
}

int pop(struct stack *p)
{
    int x;
    if (p->top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        x = p->s[p->top--];
    }
}

void display(struct stack *p)
{
    for (int j = p->top; j >= 0; j--)
    {
        printf("%d ", p->s[j]);
    }
    printf("\n");
}

int findmin(struct stack *p)
{
    return p->s[p->size -1 + i];
}

int main()
{
    struct stack p;
    int n;
    printf("enter size of stack\n");
    scanf("%d", &n);
    buildstack(&p, n);
    while (1)
    {
        printf("1 - Push()\n");
        printf("2 - Pop()\n");
        printf("3 - display()\n");
        printf("4 - findMin()\n");
        int choice;
        printf("Enter Choice\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter data\n");
            scanf("%d", &data);
            push(&p, data);
        }
        else if (choice == 2)
        {
            int y = pop(&p);
        }
        else if (choice == 3)
        {
            display(&p);
        }
        else if (choice == 4)
        {
            printf("The minimum element is :%d\n", findmin(&p));
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}