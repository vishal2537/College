#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*front=NULL,*tail=NULL;



void insertlast(int data){
    if (front==NULL)
    {
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->data=data;
        t->next=NULL;
        front=t;
        tail=t;
    }
    else
    {
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->data=data;
        t->next=NULL;
        tail->next=t;
        tail=t;
    }    
}

void rotate(struct Node* x,int k){
     struct Node* p;
     struct Node* q;
     p=x;   
      while (k!=1)
     {
        p=p->next;
        k--;
     }
     q=p->next;
     while (q->next->next!=NULL)
     {
        q=q->next;
     }
     q->next=NULL;
     tail->next=p->next;
     p->next=tail;

}

void display(struct Node* p){
    struct Node* trav=p;
    while (trav!=NULL)
    {
        printf("%d ",trav->data);
        trav=trav->next;
    }
    printf("\n");
    
}

int main(){

    int size;
    printf("Enter the size of the List\n");
    scanf("%d",&size);
    
    while (size!=0)
    {
        int data;
        printf("Enter data\n");
        scanf("%d",&data);
        insertlast(data);
        size--;
    }
    printf("The list is : ");
    display(front);
    int k;
    printf("Enter the value of k\n");
    scanf("%d",&k);
    rotate(front,k);
    display(front); 
    return 0;
}