#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*front=NULL,*tail=NULL;

void insertlast(int data){
    if (front==NULL)
    {
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->data=data;
        t->prev=NULL;
        t->next=NULL;
        front=t;
        tail=t;
    }
    else
    {
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->data=data;
        t->prev=tail;
        t->next=NULL;
        tail->next=t;
        tail=t;
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

void reverse(){
    struct Node* p=front;
    struct Node* q;
    q=front->next;
    while (q!=NULL)
    {
            front->next=front->prev;
            front->prev=q;
            front=q;
            q=q->next;
    }  
    front->next=front->prev;
    front->prev=NULL;
    tail=p;
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
    printf("The Reversed list is\n");
    reverse();
    display(front);
    return 0;
}