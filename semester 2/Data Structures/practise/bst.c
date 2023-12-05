#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} *root = NULL;

struct node *newnode(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->lchild = NULL;
    temp->rchild = NULL;

    return temp;
}

void display_inoder_traversal(struct node *p)
{
    if (p)
    {
        display_inoder_traversal(p->lchild);
        printf("%d ", p->data);
        display_inoder_traversal(p->rchild);
    }
}

void insert(int key)
{
    struct node *q = root;
    struct node *r=NULL;
    if (root == NULL)
    {
        root = newnode(key);
    }
    else
    {
        while (q != NULL)
        {
            r = q;
            if (q->data > key)
            {
                q = q->lchild;
            }
            else if (q->data < key)
            {
                q = q->rchild;
            }
            else
            {
                return;
            }
        }
        if (key < r->data)
        {
            r->lchild = newnode(key);
        }
        else if (key > r->data)
        {
            r->rchild = newnode(key);
        }
    }
}

int main()
{
    struct node *p;
    int n;
    printf("number of nodes: ");
    scanf("%d", &n);
    int i, x;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }
    display_inoder_traversal(root);
    return 0;
}