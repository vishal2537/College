#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL;

void create(int a[],int n)
{
    struct node *p,*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=NULL;
    last=head;

    for ( int i=1;i<n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=a[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }
    last->next=head;
    tail=head;
}

void rotation(struct node *w, int k)
{
    struct node*p=w;
    int a=k-1;
    while(a--)
    {
        p=p->next;
    }
    head=p;
}

void display(struct node *p)
{
    while(p->next!=head)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d ",p->data);
    printf("\n");
}

int main()
{
    int n;
    printf("enter number of element : ");
    scanf("%d", &n);

    int a[n];
    printf("enter data : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    create(a,n);

    int k;
    printf("enter k : ");
    scanf("%d", &k);


    display(head);
    rotation(head,k);
    display(head);
    return 0;
}