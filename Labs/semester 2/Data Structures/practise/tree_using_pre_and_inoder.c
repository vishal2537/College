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

void inorder(struct node *p)
{
    if (p == NULL)
    {
        return;
    }
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
}

struct node *buildtree(int inorde[], int preorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int preindex = 0;
    struct node *treenode = newnode(preorder[(preindex++)]);

    int i;
    for (i = start; i < end; i++)
    {
        if (inorde[i] == treenode->data)
        {
            break;
        }
    }
    treenode->lchild = buildtree(inorde, preorder, start, i - 1);
    treenode->rchild = buildtree(inorde, preorder, i + 1, end);
    return treenode;
}



int main()
{
    int n;
    printf("enter numebr of nodes :");
    scanf("%d", &n);
    int inorde[n], preorder[n];
    printf("enter inorder : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorde[i]);
    }
    printf("enter preorder : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    root = buildtree(inorde, preorder, 0, n-1);
    inorder(root);

    return 0;
}