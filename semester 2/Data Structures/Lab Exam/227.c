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

void sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("enter numebr of nodes :");
    scanf("%d", &n);
    int inorde[n], preorder[n];

    printf("enter preorder : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    for (int i = 0; i < n; i++)
    {
        inorde[i] = preorder[i];
    }

    sort(inorde, n);

    root = buildtree(inorde, preorder, 0, n - 1);

    printf("inorder is : ");

    inorder(root);

    return 0;
}