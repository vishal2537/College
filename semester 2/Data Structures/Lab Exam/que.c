#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*head=NULL,*tail=NULL,*head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;

void insert(struct Node* q,int data){
     
     if (head==NULL)
     {
         struct Node* t=(struct Node *)malloc(sizeof(struct Node));
         t->data=data;
         t->next=NULL;
         head=t;
         tail=t; 
     }
     else{
         struct Node* t=(struct Node *)malloc(sizeof(struct Node));
         t->data=data;
         t->next=NULL;
         tail->next=t;
         tail=t; 
     }
}

void insert1(struct Node* q,int data){
     
     if (head1==NULL)
     {
         struct Node* t=(struct Node *)malloc(sizeof(struct Node));
         t->data=data;
         t->next=NULL;
         head1=t;
         tail1=t; 
     }
     else{
         struct Node* t=(struct Node *)malloc(sizeof(struct Node));
         t->data=data;
         t->next=NULL;
         tail1->next=t;
         tail1=t; 
     }
}

void pass(struct Node* q,int data){
     
     if (head2==NULL)
     {
         struct Node* t=(struct Node *)malloc(sizeof(struct Node));
         t->data=data;
         t->next=NULL;
         head2=t;
         tail2=t; 
     }
     else{
         struct Node* t=(struct Node *)malloc(sizeof(struct Node));
         t->data=data;
         t->next=head2;
         head2=t;
         
     }

}

int Number(struct Node* p){
     int n=0;
     struct Node* trav;
     trav=p;
     
     while (trav!=NULL)
     {
         
         n = n*10+(trav->data);
         trav=trav->next;
         
     }
     return n;
     
}

void display(struct Node* q){
   struct Node* trav=q;
   while (trav!=NULL)
   {
       printf("%d->",trav->data);
       trav=trav->next;
   }
   printf("\n");
}

int main(){

    int num1;
    printf("Enter No of digit in num1\n");
    scanf("%d",&num1);
    int i=num1;
    while (i!=0)
    {
        int data;
        printf("Enter digit by digit\n");
        scanf("%d",&data);
        insert(head,data);
        i--;
    }
     int num2;
    printf("Enter No of digit in num2\n");
    scanf("%d",&num2);
    int j=num2;


    while (j!=0)
    {
        int data;
        printf("Enter digit by digit\n");
        scanf("%d",&data);
        insert1(head,data);
        j--;
    }
    printf("The first list is\n");
    display(head);
    
    printf("The second list is\n");
    display(head1);
    int x=Number(head);
    int y=Number(head1);
    int z;
    if (y>x)
    {
         z=y-x;
    }
    else
    {
        z=x-y;
    }
    
    
    
    int rem;
   
    while (z!=0)
    {
        rem=z%10;
        pass(head2,rem);
        z=z/10;
    }
    printf("The Final list is\n");
    display(head2);
    
    return 0;
}
