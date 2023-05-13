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

void Final(struct Node* t,int k){
    int temp=0;
    struct Node* p;
    struct Node* q;
    p=t;
    q=t->next;

    while (p!= NULL)
    {
        temp=p->data;
            
            while (q!=NULL)
            {
                if(temp==k)
                     break;
                temp +=q->data;
                q=q->next;
            }

            if(temp==k && p->prev==NULL && q==NULL){
                p=NULL;
                t = NULL;
                break;
            }
            if (temp==k && q==NULL && p!=NULL)
            {
                p=p->prev;
                p->next=NULL;                
            }
            else if (temp==k && q->next!=NULL && p->prev!=NULL)
            {
                p=p->prev;
                p->next=q;
                q->prev=p;
            }  

            else if (temp==k && p->prev==NULL)
            {
                q->prev=NULL;
                t =q;
                p=q;
                q=q->next;
                continue;
            }else if(temp == k && q->next==NULL){
                p=p->prev;
                p->next=q;
            }

        if (p)
        {
             p=p->next;
             if(p)
             q=p->next;
        }
    } 

    if(p)
    if(p->data==k){
        q = p->prev;
        p = NULL;
        q->next=NULL;
    }

    display(t);
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
    printf("Enter the value of K\n");
    scanf("%d",&k);
    printf("The Final list is\n");
    Final(front,k);
    
    return 0;
}