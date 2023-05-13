#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int key;
    struct tree *left, *right;
};

void insert(struct tree **p, int key)
{
    struct tree *r = NULL;

    if (*p == NULL)
    {
        struct tree *t = malloc(sizeof(struct tree));
        t->key = key;
        t->left = NULL;
        t->right = NULL;
        *p = t;
        // printf("A = %d\n", p->key);
        return;
    }

    struct tree *x = *p;

    while (x != NULL)
    {
        r = x;
        if (key == x->key)
        {
            return;
        }
        else if (key > x->key)
        {
            x = x->right;
        }
        else
        {
            x = x->left;
        }
    }

    struct tree *t = malloc(sizeof(struct tree));
    t->key = key;
    t->left = NULL;
    t->right = NULL;
    if (key > r->key)
    {
        r->right = t;
    }
    else
    {
        r->left = t;
    }
}

void printinorder(struct tree *p)
{

    if (p == NULL)
    {
        return;
    }
    printinorder(p->left);
    printf("%d ", p->key);
    printinorder(p->right);
}
int main()
{
    int n;
    struct tree *temp = NULL;
    printf("Enter the size of array\n");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // insert(temp, 1);

    for (int i = 0; i < n; i++)
    {
        insert(&temp, arr[i]);
    }

    printinorder(temp);
}