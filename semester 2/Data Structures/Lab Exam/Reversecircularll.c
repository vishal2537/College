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
        front=t;
        t->next=front;
        tail=t;
        tail->next=front;
    }

    else
    {
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->data=data;
        t->next=front;
        tail->next=t;
        tail=t;
    }
    
}

void display(struct Node* p){
    struct Node* trav=p;
    while (trav!=tail)
    {
        printf("%d ",trav->data);
        trav=trav->next;
    }
    printf("%d ",trav->data);
    printf("\n");
    
}
void reverse(struct Node* x){
    struct Node* prev;
    struct Node* curr;
    struct Node* nextnode;
    prev=x;
    curr=prev->next;
    nextnode=curr->next;
    
    // printf("prev=%d\n",prev->data);
    // printf("curr=%d\n",curr->data);
    // printf("nextnode=%d\n",nextnode->data);
    while (prev!=tail)
    {
    // printf("prev=%d\n",prev->data);
    // printf("curr=%d\n",curr->data);
    // printf("nextnode=%d\n",nextnode->data);
    
        curr->next=prev;
        prev=curr;
        curr=nextnode;
        nextnode=nextnode->next;
    }
    tail=curr;
    front=prev;

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
    reverse(front);
    display(front);
    return 0;
}