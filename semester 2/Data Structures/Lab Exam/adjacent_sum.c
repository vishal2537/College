#include<stdio.h>
#include<stdlib.h>

 struct queue
 {
    int front;
    int rear;
    int size;
    int *Q;
 };
 
void create(struct queue* q,int size){
    q->size=size;
    q->Q=(int *)malloc(q->size*sizeof(int));
    q->front=-1;
    q->rear=-1;
}

void enqueue(struct queue* p,int data){
    
    if (p->front==-1)
    {
        p->front++;
        p->rear++;
        p->Q[p->rear]=data;
    }
    else
    {
        p->rear=(p->rear+1)%p->size;
        p->Q[p->rear]=data;
    }   

}

void display(struct queue* p){

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

int find(struct queue* q){
    int i=q->front;
    int count=0;

    while (i!=q->rear)
    {
        if ((q->Q[i]+q->Q[i+1])%2==0)
        {
            count++;
        }
        i=(i+1)%q->size;
    }
    if ((q->Q[q->front]+q->Q[q->rear])%2==0)
    {
         count++;
    }
    

    return count;
}

int main(){
     struct queue q;
     int size;
     printf("Enter the size of the circular queue\n");
     scanf("%d",&size);
     create(&q,size);
     while (size!=0)
     {
        int data;
        printf("Enter Data\n");
        scanf("%d",&data);
        enqueue(&q,data);
        size--;
     }
     printf("The final queue is\n");
     display(&q);

     printf("The no of adjacent pair is : %d\n",find(&q));

    return 0;
}