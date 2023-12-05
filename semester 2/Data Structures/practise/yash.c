#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int hd;
} *root = NULL, *nRoot = NULL;

struct node *newnode(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *createtree(int pre[], int in[], int start, int end)
{
    static int p = 0;

    if (start > end)
        return NULL;

    struct node *root = newnode(pre[p++]);

    int i;
    for (int idx = start; idx <= end; idx++)
    {
        if (in[idx] == root->data)
            i = idx;
    }

    root->left = createtree(pre, in, start, i - 1);
    root->right = createtree(pre, in, i + 1, end);

    return root;
}

void displayin(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        displayin(root->left);
        printf("%d ", root->data);
        displayin(root->right);
    }
}
void displaypre(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        printf("%d ", root->data);
        displaypre(root->left);
        displaypre(root->right);
    }
}
int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int maxhd = 0;
struct node *mhd = NULL;
int abs(int x)
{
    if (x < 0)
        return -x;
    else
        return x;
}
void update(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        update(root->left);
        root->hd = height(root->left) - height(root->right);
        update(root->right);
        if (maxhd <= abs(root->hd))
        {
            maxhd = abs(root->hd);
            mhd = root;
        }
    }
}
struct node *t = NULL;
struct node *find(int k, struct node *root)
{
    if (root == NULL)
        return NULL;
    else if (root->data == k)
        return root;

    t = find(k, root->left);
    if (t != NULL)
        return t;

    t = find(k, root->right);
    if (t != NULL)
        return t;
}

int c = 0;
void newTree(int k1, struct node **nRoot)
{
    if (c == 2)
    {
        ((*nRoot)->left)->left = newnode(k1);
    }
    else if (c == 3)
    {
        (*nRoot)->right = newnode(k1);
    }
    else if (c == 4)
    {
        ((*nRoot)->left)->right = newnode(k1);
    }

    else if (c == 5)
    {
        ((*nRoot)->right)->left = newnode(k1);
    }
    else
    {
        ((*nRoot)->right)->right = newnode(k1);
    }
    c++;
    if (c == 7)
    {
        if (mhd->hd <= 0)
        {
            while (mhd->right != NULL)
            {
                mhd = mhd->right;
            }
            mhd->right = (*nRoot);
        }
        else
        {
            while (mhd->left != NULL)
            {
                mhd = mhd->left;
            }
            mhd->left = (*nRoot);
        }
        *nRoot = NULL;
        return;
    }
    displaypre((*nRoot));
    printf("\n");
}

int f = 0;
void insertChild(int k1, int k2, struct node *root)
{
    struct node *temp = find(k2, root);
    if (temp == NULL)
    {
        printf("going to new Tree\n");
        if (nRoot == NULL)
        {
            nRoot = newnode(k2);
            nRoot->left = newnode(k1);
            c = 2;
        }
        else
            newTree(k1, &nRoot);
    }
    else if (temp->hd > 0)
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = newnode(k1);
    }
    else
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        temp->left = newnode(k1);
    }
}
int flag = 0;
struct node *findleaf(struct node *root, struct node *temp)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL && flag == 0)
    {
        temp->data = root->data;
        flag = 1;
        root = NULL;
        return NULL;
    }
    root->left = findleaf(root->left, temp);
    root->right = findleaf(root->right, temp);
    return root;
}

void del(int k, struct node **root)
{
    if (*root == NULL)
        return;
    if ((*root)->data == k && flag == 0)
    {
        flag = 1;
        *root = NULL;
        return;
    }
    del(k, &((*root)->left));
    del(k, &((*root)->right));
}

void deletenode(int k, struct node *root)
{
    struct node *temp = find(k, root);
    if (temp != NULL)
    {
        flag = 0;
        if (temp->left == NULL && temp->right == NULL)
        {
            del(k, &root);
        }
        else if (temp->hd >= 0)
        {
            temp->left = findleaf(temp->left, temp);
        }
        else
        {
            temp->right = findleaf(temp->right, temp);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int pre[n], in[n];
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &pre[j]);
    }
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &in[j]);
    }
    // int n=5;
    // int pre[] = {1,2,4,3,5};
    // int in[] = {4,2,1,3,5};
    struct node *root = createtree(pre, in, 0, n - 1);
    update(root);
    while (1)
    {
        printf("1: insert child 2: delete node 3:display 4: find 5: exit 6: displaynew\n");
        int q;
        scanf("%d", &q);
        switch (q)
        {
        case (1):
        {
            int k1, k2;
            scanf("%d %d", &k1, &k2);
            if (find(k1, root) == NULL)
            {
                insertChild(k1, k2, root);
            }
            update(root);
            break;
        }
        case (2):
        {
            int k;
            scanf("%d", &k);
            deletenode(k, root);
            update(root);
            break;
        }
        case (3):
        {
            displaypre(root);
            printf("\n");
            displayin(root);
            printf("\n");
            break;
        }
        case (4):
        {
            int k;
            scanf("%d", &k);
            struct node *temp = find(k, root);
            if (temp != NULL)
                printf("%d\n", temp->data);
            else
                printf("not found\n");
            break;
        }
        case (5):
        {
            return 0;
        }
        case (6):
        {
            displaypre(nRoot);
            printf("\n");
            displayin(nRoot);
            printf("\n");
            break;
        }
        default:
        {
            printf("choose another num");
            break;
        }
        }
    }
}
