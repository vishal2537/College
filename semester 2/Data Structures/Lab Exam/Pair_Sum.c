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

// void duplicate(struct Node* x){

//     struct Node* p;
//     struct Node* q;
//     p=x;
//     q=x;
//     p=p->next;
//     while (p!=NULL)
//     {
//         if (q->data==p->data)
//         {
//            q->next=p->next;
//            p=q->next; 
            
//         }
//         else 
//         {
//             q=p;
//             p=p->next;
//         }
//     }
    
// }

void pair(struct Node* x,int data){

    struct Node* p;
    struct Node* q;
    p=x->next;
    q=x;
    int i=1,j=2;  

    while (q->next!=NULL)
    {
        
        while (p!=NULL)
        {
            if (p->data + q->data==data)
            {
                printf("Node %d and Node %d\n",i,j);
               
            } 
            p=p->next;  
            j++;         
        }
        q=q->next;
        i++;
        if (q->next!=NULL)
        {
             p=q->next;
             j=i+1;
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
    printf("Enter K\n");
    int k;
    scanf("%d",&k);
    pair(first,k);    
    
    return 0;

}