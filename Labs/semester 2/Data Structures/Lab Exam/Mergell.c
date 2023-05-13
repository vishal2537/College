#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*front=NULL,*tail=NULL,*front1=NULL,*tail1=NULL;



void insertlast(struct Node* p,int data){
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


void insertlast1(struct Node* p,int data){
    if (front1==NULL)
    {
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->data=data;
        t->next=NULL;
        front1=t;
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

void merge(struct Node* x,struct Node* y){
    struct Node* p;
    struct Node* q;
    struct Node* r;
        
    p=x;
    q=x->next;
    r=y;

    while (q!=NULL && r!=NULL)
    {
        if (q->data<r->data)
        {
            p->next=q;
            p=q;
            q=q->next;
        }
        else 
        {
           p->next=r;
           p=r;
           r=r->next;
        }
        if (q==NULL && r!=NULL)
        {
            p->next=r;
            p=r;
            r=r->next;
        }
        else if (q!=NULL && r==NULL)
        {
           p->next=q;
            p=q;
            q=q->next;
        }
        
        
    }
    
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
    printf("Enter the size of the List-1\n");
    scanf("%d",&size);
    

    int size1;
    printf("Enter the size of the List-2\n");
    scanf("%d",&size1);
    
    printf("Enter data for list-1\n");
    while (size!=0)
    {
        int data;
        printf("Enter data\n");
        scanf("%d",&data);
        insertlast(front,data);
        size--;
    }
    printf("Enter data for list-2\n");
    while (size1!=0)
    {
        int data;
        printf("Enter data\n");
        scanf("%d",&data);
        insertlast1(front1,data);
        size1--;
    }
    
    printf("The List-1 is : ");
    display(front);

    printf("The List-2 is : ");
    display(front1);

    merge(front,front1);
    printf("The final list is :\n");
    display(front);

    return 0;
}