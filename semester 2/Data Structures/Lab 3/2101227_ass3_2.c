#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void buildStack1(struct stack *s1)
{
    printf("Enter the size of stack\n");
    scanf("%d", &s1->size);
    s1->top = -1;
    s1->s = (int *)malloc(s1->size * (sizeof(int)));
}

void buildStack2(struct stack *s2)
{
    s2->size = 50;
    s2->top = -1;
    s2->s = (int *)malloc(s2->size * (sizeof(int)));
}

void push(struct stack *s1, struct stack *s2, int x)
{
    if (s1->top == s1->size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s1->top++;
        s1->s[s1->top] = x;
        if (s2->top == -1)
        {
            s2->top++;
            s2->s[s2->top] = x;
        }
        else if (x <= (s2->s[s2->top]))
        {
            s2->top++;
            s2->s[s2->top] = x;
        }
    }
}

int pop(struct stack *s1, struct stack *s2)
{
    int x = -1;
    if (s1->top == -1)
        printf("Stack underflow\n");
    else
    {
        x = s1->s[s1->top];
        s1->top--;
        if (x <= s2->s[s2->top])
            s2->top--;
    }
    return x;
}

int isEmpty(struct stack s1)
{
    if (s1.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack s1)
{
    if (s1.top == s1.size - 1)
        return 1;
    else
        return 0;
}

void display(struct stack s1)
{
    int i;
    for (int i = s1.top; i >= 0; i--)
    {
        printf("%d ", s1.s[i]);
    }
    printf("\n");
}

int findMin(struct stack s2)
{
    printf("\nminimum value of stack : %d\n", s2.s[s2.top]);
}

int main()
{
    struct stack s1;
    struct stack s2;
    buildStack1(&s1);
    buildStack2(&s2);

    printf("Enter no of elements you want to enter in the stack\n");
    int n;
    scanf("%d", &n);
    printf("Enter elements\n");
    int x;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        push(&s1, &s2, x);
    }
    int ch;

    while (1)
    {
        printf("0=exit 1=push 2=pop 3=isEmpty 4=isFull 5=findMin \n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int value;
            printf("enter value to add to stack\n");
            scanf("%d", &value);
            push(&s1, &s2, value);
            display(s1);
        }
        else if (ch == 2)
        {
            pop(&s1, &s2);
            display(s1);
        }
        else if (ch == 3)
        {
            if (isEmpty(s1) == 1)
            {
                printf("\nstack is empty\n");
            }
            else
            {
                printf("\nstack isnot empty\n");
            }
        }
        else if (ch == 4)
        {
            if (isFull(s1) == 1)
            {
                printf("\nstack is full\n");
            }
            else
            {
                printf("\nstack isnot full\n");
            }
        }
        else if (ch == 5)
        {
            findMin(s2);
        }
    }
    return 0;
}