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
void reverse(){
     struct Node* p;
     struct Node* q;
     struct Node* r;
     r=NULL;
     p=front;
     q=p->next;

     while (q!=NULL)
     {
        p->next=r;
        r=p;
        p=q;
        q=q->next;
     }
     p->next=r;
     r=p;
     p=NULL;
     front=r;     

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
    printf("The Reversed list is\n");
    reverse();
    display(front);
    return 0;
}