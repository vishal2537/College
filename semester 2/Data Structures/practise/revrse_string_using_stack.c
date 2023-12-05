#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *s;
};

void create(struct stack *p)
{
    p->top = -1;
    printf("enter size of string : ");
    scanf("%d", &(p->size));
    p->s = (char *)malloc(p->size * sizeof(char));
}

void push(struct stack *p, char data)
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
}

// void pop(struct stack *p)
// {
//     int x;
//     if(p->top==-1)
//     {
//         printf("stack underflow\n");
//     }
//     else
//     {
//         x=p->s[p->top--];
//     }
// }

void display(struct stack *p)
{
    for (int i = p->top; i >= 0; i--)
    {
        printf("%c ", p->s[i]);
    }
    printf("\n");
}

int main()
{
    struct stack *p;
    create(p);
    char a[100];
    printf("enter the string : ");
    scanf("%s", &a);

    for (int i = 0; i < p->size; i++)
    {
        push(p, a[i]);
    }

    display(p);

    return 0;
}