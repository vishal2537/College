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
            if (x < p->data)
            {
                p = p->lchild;
            }
            else if (x > p->data)
            {
                p = p->rchild;
            }
            else
            {
                return;
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

struct node *search(struct node *p, int x)
{
    while (p != NULL)
    {
        if (x == p->data)
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
}

int height(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int x = height(p->lchild);
    int y = height(p->rchild);

    return x > y ? x + 1 : y + 1;
}

struct node *inoderpre(struct node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

struct node *inodersucce(struct node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

struct node *delete (struct node *p, int x)
{
    struct node *q = NULL;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        p = NULL;
        free(p);
        return NULL;
    }
    else
    {
        if (x < p->data)
        {
            p->lchild = delete (p->lchild, x);
        }
        else if (x > p->data)
        {
            p->rchild = delete (p->rchild, x);
        }
        else
        {
            if (height(p->lchild) > height(p->rchild))
            {
                q = inoderpre(p->lchild);
                p->data = q->data;
                p->lchild = delete (p->lchild, q->data);
            }
            else
            {
                q = inodersucce(p->rchild);
                p->data = q->data;
                p->rchild = delete (p->rchild, q->data);
            }
        }
    }
}

int main()
{
    int n, x;
    printf("enter number of node :");
    scanf("%d", &n);
    printf("\nenter node : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }

    inorder_traversal(root);

    int key;
    printf("enter key you to search in bst :");
    scanf("%d", &key);

    struct node *temp = search(root, key);

    if (temp->data == key)
    {
        printf("element present in bst ");
    }
    else
    {
        printf("not presenst\n");
    }
    int w;
    printf("enter nunmber you want to delete :");
    scanf("%d", &w);

    temp = delete (root, w);
    inorder_traversal(root);

    return 0;
}