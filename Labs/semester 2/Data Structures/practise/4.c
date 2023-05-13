#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *Q;
};

int i=0;

void buildstack(struct stack* p,int size){
    struct stack *t=p;
    t->size=size;
    t->top=-1;
    t->Q=(int *)malloc((t->size*2)*sizeof(int));
}

void isEmpty(struct stack* p){

    if (p->top==-1)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        printf("Not Empty\n");
    }
}

void isFull(struct stack* p){
     if (p->top==p->size-1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        printf("Not Full\n");
    }
}

void push(struct stack* p,int data){
   
   if (p->top==p->size-1)
   {
       printf("Stack Overflow\n");
   }
   else
   {
       p->top++;
       p->Q[p->top]=data;
   }
    
   if (p->top==0)
   {
       p->Q[p->size+i]=data;
       i++;
    
   }
   
   else if (p->Q[p->size-1+i]>data)
   {
       p->Q[p->size+i]=data;
       i++;
   }
}

int pop(struct stack* p){

    int x;
    if (p->top==-1)
    {
        return -1;
    }
    else
    {
        x=p->Q[p->top];
        p->top--;
    }
    return x;
}

int top(struct stack* p){
    if (p->top==-1)
    {
        return -1;
    }
    else
    {
        return p->Q[p->top];
    }  
}

int findmin(struct stack* p){
    return p->Q[p->size-1+i];
}

int main(){

    struct stack q;
    int size;
    printf("Enter the size of Stack\n");
    scanf("%d",&size);
    buildstack(&q,size);


    while (1)
    {
        printf("1 - isEmpty()\n");
        printf("2 - Push()\n");
        printf("3 - Pop()\n");
        printf("4 - Top()\n");
        printf("5 - isFull()\n");
        printf("6 - findMin()\n");
        printf("7 - Exit\n");
        int choice;

        printf("Enter Choice\n");
        scanf("%d",&choice);

        if (choice==1)
        {
            isEmpty(&q);
        }
        else if (choice==2)
        {
            int data;
            printf("Enter data\n");
            scanf("%d",&data);
            push(&q,data);
        }
        else if (choice==3)
        {
            int y=pop(&q);
            if (y==-1)
            {
               printf("Stack Underflow\n");   
            }
            else
            {
                printf("The popped element is :\n%d\n",y);
            }
        }
        else if (choice==4)
        {
            int x=top(&q);
            if (x==-1)
            {
                printf("Stack Underflow!\n");
            }
            else
            {
                printf("The Top element is :\n%d\n",x);
            }
             
        }
        else if (choice==5)
        {
            isFull(&q);
        }
        else if (choice==6)
        {
            printf("The minimum element is :%d\n",findmin(&q));
        }
        
        else if (choice==7)
        {
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }
            
    }
    

    return 0; 
}