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

void insert(int x)
{
    struct node *p = root;
    struct node *q = NULL;
    if (root == NULL)
    {
        root = newnode(x);
    }
    else
    {
        while (p != NULL)
        {
            q = p;
            if (p->data == x)
            {
                return;
            }
            else if (p->data > x)
            {
                p = p->lchild;
            }
            else
            {
                p = p->rchild;
            }
        }
        if (q->data > x)
        {
            q->lchild = newnode(x);
        }
        else
        {
            q->rchild = newnode(x);
        }
    }
}

struct node *search(int x)
{
    struct node *p = root;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p;
        }
        else if (x < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    return NULL;
}

int height(struct node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct node *inorderpredecessor(struct node *p)
{
    while (p && p->rchild != 0)
    {
        p = p->rchild;
    }
    return p;
}

struct node *inordersuccessessor(struct node *p)
{
    while (p && p->lchild != 0)
    {
        p = p->lchild;
    }
    return p;
}

struct node *delete (struct node *p, int key)
{
    struct node *r = root;
    struct node *q=NULL;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    else
    {
        if (key < p->data)
        {
            p->lchild = delete (p->lchild, key);
        }
        else if (key > p->data)
        {
            p->rchild = delete (p->rchild, key);
        }
        else
        {
            if (height(p->lchild) > height(p->rchild))
            {
                q = inorderpredecessor(p->lchild);
                p->data = q->data;
                p->lchild = delete (p->lchild, q->data);
            }
            else
            {
                q = inordersuccessessor(p->rchild);
                p->data = q->data;
                p->rchild = delete (p->rchild, q->data);
            }
        }
        return p;
    }
}

int main()
{
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }
    inorder_traversal(root);
    int key;
    scanf("%d", &key);
    struct node *temp = delete (root, key);
    inorder_traversal(root);

    return 0;
}