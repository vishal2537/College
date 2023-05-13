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

struct node *buildtree(int in[], int pre[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int preindex = 0;

    struct node *temp = newnode(pre[preindex++]);

    int i;
    for (i = start; i <= end; i++)
    {
        if (in[i] == temp->data)
        {
            break;
        }
    }

    temp->lchild = buildtree(in, pre, start, i - 1);
    temp->rchild = buildtree(in, pre, i + 1, end);

    return temp;
}

int count_number_of_nodes(struct node *p)
{
    if (p)
    {
        return count_number_of_nodes(p->lchild) + count_number_of_nodes(p->rchild) + 1;
    }
    return 0;
}

int count_leaf_node(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (!p->lchild && !p->rchild)
    {
        return count_leaf_node(p->lchild) + count_leaf_node(p->rchild)+1;
    }
    return count_leaf_node(p->lchild) + count_leaf_node(p->rchild);
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

    root = buildtree(inorde, preorder, 0, n - 1);
    inorder(root);

    printf("\nno. of nodes : %d", count_number_of_nodes(root));
    printf("\nno. of leaf nodes : %d", count_leaf_node(root));

    return 0;
}