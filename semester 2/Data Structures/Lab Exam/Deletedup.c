#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first=NULL;

void insert(int data){

        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->data=data;
        t->next=first;
        first=t;    
}

void display(struct Node* p){
    struct Node* t=p;

    while (t!=NULL)
    {
       printf("%d ",t->data);
       t=t->next;
    }
    printf("\n");
}

void duplicate(struct Node* x){

    struct Node* p;
    struct Node* q;
    p=x;
    q=x;
    p=p->next;
    while (p!=NULL)
    {
        if (q->data==p->data)
        {
           q->next=p->next;
           p=q->next; 
            
        }
        else 
        {
            q=p;
            p=p->next;
        }
    }
    
}

int main(){
    int n;
    printf("Enter the size of linked list\n");
    scanf("%d",&n);

    while (n!=0)
    {
        int data;
        printf("Enter Data\n");
        scanf("%d",&data);
        insert(data);
        n--;
    }
    printf("The Entered list is : ");
    display(first);
    printf("To Remove Duplicate Press 1\n");
    int choice;
    scanf("%d",&choice);
    if (choice==1)
    {
        duplicate(first);
        printf("The Final list is : ");
        display(first);
    }
    
    
    return 0;
}