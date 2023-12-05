#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} *root = NULL;

struct node *newnode(int key)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->lchild = temp->rchild = NULL;

    return temp;
}

void inorder_traversal(struct node *p)
{
    if (p)
    {
        inorder_traversal(p->lchild);
        printf("%d ", p->data);
        inorder_traversal(p->rchild);
    }
}

void insert(int key)
{
    struct node *p = root;
    struct node *q = NULL;
    if (root == NULL)
    {
        root = newnode(key);
    }
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(key<p->data)
            {
                p=p->lchild;
            }
            else if(key>p->data)
            {
                p=p->rchild;
            }
            else
            {
                return;
            }
        }
        if(key<q->data)
        {
            q->lchild=newnode(key);
        }
        else if(key>q->data)
        {
            q->rchild=newnode(key);
        }
    }
}

struct node* search(int key)
{
    struct node *t=root;
    while(t!=NULL)
    {
        if (t->data==key)
        {
            return t;
        }
        else if(t->data>key)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    return NULL;
}

int main()
{
    int n,i,x;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&x);
        insert(x);
    }
    inorder_traversal(root);
    int key;
    scanf("%d",&key);
    struct node *temp=search(key);
    printf("%d",temp->data);
    
    return 0;
}
