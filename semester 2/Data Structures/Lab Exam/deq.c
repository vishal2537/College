#include<stdio.h>
#include<stdlib.h>

struct deq
{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct deq* q,int size){
     q->size=size;
     q->front=-1;
     q->rear=-1;
     q->Q=(int *)malloc(size*sizeof(int));
}

void insertfront(struct deq* q,int data){
     if (q->front==-1 && q->rear==-1)
     {
        q->front++;
        q->rear++;
        q->Q[q->rear]=data;
     }
     else if ((q->front-1)==q->rear+1)
     {
        printf("Queue is Full!\n");    
     }
     else{
        q->front=(q->front-1)%q->size;
        q->Q[q->front]=data;
     }
     
}
void insertrear(struct deq* q,int data){
    if (q->front==-1 && q->rear==-1)
    {
        q->front++;
        q->rear++;
        q->Q[q->rear]=data;
    }
    else if ((q->rear+1)%q->size==q->front)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=data;
    }    
}
void display(struct deq* q){
    int i=q->front;

    while (i!=q->rear)
    {
        printf("%d ",q->Q[i]);
        i=(i+1)%q->size;
    }
    printf("%d ",q->Q[i]);
    printf("\n");
}

int main(){
    struct deq q;
    int size;
    printf("Enter the size of queue\n");
    scanf("%d",&size);
    create(&q,size);
    
        printf("front=%d\n",q.front);
        printf("rear=%d\n",q.rear);
        insertrear(&q,1);
         printf("front=%d\n",q.front);
        printf("rear=%d\n",q.rear);
        insertrear(&q,2);
         printf("front=%d\n",q.front);
        printf("rear=%d\n",q.rear);
        insertrear(&q,3);
         printf("front=%d\n",q.front);
        printf("rear=%d\n",q.rear);
        insertrear(&q,4);
         printf("front=%d\n",q.front);
        printf("rear=%d\n",q.rear);
        insertrear(&q,5);
         printf("front=%d\n",q.front);
        printf("rear=%d\n",q.rear);
        insertrear(&q,6);
         printf("front=%d\n",q.front);
        printf("rear=%d\n",q.rear);
        insertrear(&q,7);
         printf("front=%d\n",q.front);
        printf("rear=%d\n",q.rear);
        size--;

    
    printf("The List is :\n");
    display(&q);
    
    return 0;
}