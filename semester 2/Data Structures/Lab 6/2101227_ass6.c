#include <stdio.h>
#include <stdlib.h>
struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
    int hd;
};
struct tnode *newNode(int key)
{
    struct tnode *tnode = malloc(sizeof(struct tnode));
    tnode->data = key;
    tnode->left = NULL;
    tnode->right = NULL;
    return tnode;
}

int power(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    return base * power(base, exp - 1);
}
int absolute(int x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}
int height(struct tnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left = height(root->left);
        int right = height(root->right);
        if (left > right)
        {
            return (left + 1);
        }
        else
        {
            return (right + 1);
        }
    }
}
void check(struct tnode *curr, int key, int *flag)
{
    if (curr == NULL)
    {
        return;
    }
    if (curr->data == key)
    {
        *flag = 1;
    }
    check(curr->left, key, flag);
    check(curr->right, key, flag);
}
void updateTree(struct tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    root->hd = height(root->left) - height(root->right);
    updateTree(root->left);
    updateTree(root->right);
}
void maxHD(struct tnode *root, int *maxhd)
{
    if (root == NULL)
    {
        return;
    }
    if (absolute(root->hd) > absolute(*maxhd))
    {
        *maxhd = root->hd;
    }
    maxHD(root->left, maxhd);
    maxHD(root->right, maxhd);
}
void insertMaxHD(struct tnode *root, struct tnode *secondRoot, int maxhd, int *flag)
{
    if (root == NULL || *flag == 1)
    {
        return;
    }
    if (root->hd == maxhd)
    {
        if ((root->hd) > 0)
        {
            if (root->left == NULL)
            {
                root->left = secondRoot;
            }
            else
            {
                while (root->left != NULL)
                {
                    root = root->left;
                }
                root->left = secondRoot;
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = secondRoot;
            }
            else
            {
                while (root->right != NULL)
                {
                    root = root->right;
                }
                root->right = secondRoot;
            }
        }
        *flag = 1;
    }
    insertMaxHD(root->left, secondRoot, maxhd, flag);
    insertMaxHD(root->right, secondRoot, maxhd, flag);
}

void countNodes(struct tnode *root, int *count)
{
    if (root == NULL)
    {
        return;
    }
    countNodes(root->left, count);
    (*count)++;
    countNodes(root->right, count);
}
void countNodesAtLevel(struct tnode *root, int level, int *count)
{
    if (level == 0 || root == NULL)
    {
        return;
    }
    else if (level == 1)
    {
        (*count)++;
    }
    else if (level > 1)
    {
        countNodesAtLevel(root->left, level - 1, count);
        countNodesAtLevel(root->right, level - 1, count);
    }
}

void inordertraversal(struct tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    inordertraversal(root->left);
    printf("[ %d ] - { hd : %d }--->", root->data, root->hd);
    inordertraversal(root->right);
}
void preordertraversal(struct tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("[ %d ] - { hd : %d }--->", root->data, root->hd);
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(struct tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    printf("[ %d ] - { hd : %d }--->", root->data, root->hd);
}

struct tnode *initTreeFromPreAndIn(int inOrder[], int preOrder[], int front, int rear, int *preIndex)
{
    if (front > rear)
    {
        return NULL;
    }
    struct tnode *newnode = newNode(preOrder[(*preIndex)++]);
    int r;
    for (int i = front; i <= rear; i++)
    {
        if (inOrder[i] == newnode->data)
        {
            r = i;
            break;
        }
    }
    newnode->left = initTreeFromPreAndIn(inOrder, preOrder, front, r - 1, preIndex);
    newnode->right = initTreeFromPreAndIn(inOrder, preOrder, r + 1, rear, preIndex);
    return newnode;
}
struct tnode *treeFromPreAndIn(int preOrder[], int inOrder[], int size)
{
    int preIndex = 0;
    return initTreeFromPreAndIn(inOrder, preOrder, 0, size - 1, &preIndex);
}

void insert(struct tnode *root, int key)
{
    if (root->left == NULL)
    {
        root->left = newNode(key);
        root->left->hd = 0;
    }
    else if (root->right == NULL)
    {
        root->right = newNode(key);
        root->right->hd = 0;
    }
}
void ninsertchild(struct tnode *root, int key1, int key2)
{
    if (root != NULL)
    {
        if (root->data == key2)
        {
            if (root->left != NULL && root->right != NULL)
            {
                if (root->hd > 0)
                {
                    insert(root->right, key1);
                }
                else
                {
                    insert(root->left, key1);
                }
            }
            else
            {
                if (root->left == NULL)
                {
                    root->left = newNode(key1);
                }
                else
                {
                    root->right = newNode(key1);
                }
            }
        }
        else
        {
            ninsertchild(root->left, key1, key2);
            ninsertchild(root->right, key1, key2);
        }
    }
}
void insertChild(struct tnode *root, int key1, int key2)
{
    int checkFlag = 0;
    int keyTwoCheckFlag = 0;
    check(root, key1, &checkFlag);
    check(root, key2, &keyTwoCheckFlag);
    if (checkFlag == 1)
    {
        printf("already present\n");
        return;
    }
    if (keyTwoCheckFlag == 0)
    {
        printf("not found\n");
        return;
    }
    ninsertchild(root, key1, key2);
    updateTree(root);
}

void delete (struct tnode **root, int *key, int *flag)
{
    if (*root == NULL || *flag == 1)
    {
        return;
    }
    if ((*root)->left == NULL && (*root)->right == NULL)
    {
        *flag = 1;
        *key = (*root)->data;
        *root = NULL;
        return;
    }
    delete (&((*root)->left), key, flag);
    delete (&((*root)->right), key, flag);
}
void ndeletenode(struct tnode **root, int key)
{
    if (*root == NULL)
    {
        return;
    }
    if ((*root)->data == key)
    {
        int flag = 0;
        int replacementKey;
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            *root = NULL;
            return;
        }
        else
        {
            if ((*root)->hd >= 0)
            {
                delete (&((*root)->left), &replacementKey, &flag);
            }
            else
            {
                delete (&((*root)->right), &replacementKey, &flag);
            }
            (*root)->data = replacementKey;
        }
    }
    ndeletenode(&((*root)->left), key);
    ndeletenode(&((*root)->right), key);
}
void deleteNode(struct tnode *root, int key)
{
    int flag = 0;
    check(root, key, &flag);
    if (flag == 0)
    {
        printf("keynot found\n");
        return;
    }
    ndeletenode(&root, key);
}

void levelInsert(struct tnode *root, int level, int key, int *done)
{
    if (level == 0 || *done == 1)
    {
        return;
    }
    else if (level == 1)
    {
        if (root->left == NULL)
        {
            root->left = newNode(key);
            *done = 1;
        }
        else if (root->right == NULL)
        {
            root->right = newNode(key);
            *done = 1;
        }
    }
    else if (level > 1)
    {
        levelInsert(root->left, level - 1, key, done);
        if (root->right == NULL && *done == 0)
        {
            root->right = newNode(key);
            *done = 1;
        }
        levelInsert(root->right, level - 1, key, done);
    }
}
void levelCheck(struct tnode *root, int level, int key)
{
    int allNodes = power(2, level - 1);
    int currNodes = 0;
    countNodesAtLevel(root, level, &currNodes);
    int count = 0;
    countNodesAtLevel(root, level + 1, &count);
    if (currNodes == allNodes - 1 && count == 0)
    {
        levelCheck(root, level + 1, key);
    }
    else
    {
        int done = 0;
        levelInsert(root, level - 1, key, &done);
    }
}
void reInsertChild(struct tnode *root, struct tnode **secondRoot, int key1, int key2)
{
    int checkFlag = 0;
    int keyTwoCheckFlag = 0;
    check(root, key1, &checkFlag);
    check(root, key2, &keyTwoCheckFlag);
    if (checkFlag == 1)
    {
        printf("key already exist\n");
        return;
    }
    if (keyTwoCheckFlag == 0)
    {
        if (*secondRoot == NULL)
        {
            *secondRoot = newNode(key2);
            insert(*secondRoot, key1);
        }
        else
        {
            int count = 0;
            countNodes(*secondRoot, &count);
            if (count == 6)
            {
                (*secondRoot)->right->right = newNode(key1);
                int m = 0;
                maxHD(root, &m);
                int flag = 0;
                insertMaxHD(root, *secondRoot, m, &flag);
                *secondRoot = NULL;
            }
            else if (count < 6)
            {
                int h = height(*secondRoot);
                levelCheck(*secondRoot, h, key1);
            }
        }
    }
    ninsertchild(root, key1, key2);
    updateTree(root);
}

int main()
{
    struct tnode *tree = NULL;
    struct tnode *secondtree = NULL;
    int n;
    printf("enter number of node in tree  : \n");
    scanf("%d", &n);

    int inorder[n];
    printf("enter the inorder : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
    }

    int preorder[n];
    printf("enter the preorder : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    int ch;

    while (1)
    {
        printf("\n\n1.buildTree()\n2.insertChild()\n3.deleteNode()\n4.reInsertChild()\n5.print()\n6.exit\n\n");
        printf("enter choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            tree = treeFromPreAndIn(preorder,inorder,n);
            updateTree(tree);
        }

        else if (ch == 2)
        {
            int key1, key2;
            printf("\n enter key 1 and key2 : \n");
            scanf("%d%d", &key1, &key2);
            insertChild(tree,key1,key2);
            updateTree(tree);
        }
        else if (ch == 3)
        {
            int key;
            printf("Enter key to delete\n");
            scanf("%d", &key);
            deleteNode(tree, key);
            updateTree(tree);
        }
        else if (ch == 4)
        {
            int key1, key2;
            printf("Enter key1\n");
            scanf("%d", &key1);
            printf("Enter key2\n");
            scanf("%d", &key2);
            reInsertChild(tree, &secondtree, key1, key2);
            updateTree(tree);
            updateTree(secondtree);
        }
        else if (ch == 5)
        {
            printf("1.MainTree()\n2.SecondTree()");
            printf("\nenter choice : ");
            int cho;
            scanf("%d", &cho);
            if (cho == 1)
            {
                int count = 0;
                countNodes(tree, &count);
                if (count == 0)
                {
                    printf("\nTree is Empty!\n");
                }
                else
                {
                    printf("\n1.inorder()");
                    printf("\n2.preorder()");
                    printf("\n3.postorder()");
                    int choice;
                    printf("\nenter choice : ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                        inordertraversal(tree);
                    }
                    else if (choice == 2)
                    {
                        preordertraversal(tree);
                    }
                    else if (choice == 3)
                    {
                        postordertraversal(tree);
                    }
                    printf("\n");
                }
            }
            else if (cho == 2)
            {
                int count = 0;
                countNodes(secondtree, &count);
                if (count == 0)
                {
                    printf("Tree is Empty!\n");
                }
                else
                {
                    printf("\n1.inorder()");
                    printf("\n2.preorder()");
                    printf("\n3.postorder()");
                    int choice;
                    printf("\nenter choice : ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                        inordertraversal(secondtree);
                    }
                    else if (choice == 2)
                    {
                        preordertraversal(secondtree);
                    }
                    else if (choice == 3)
                    {
                        postordertraversal(secondtree);
                    }
                    printf("\n");
                }
            }
        }
        else
        {
            printf("invalid\n");
        }
    }

    return 0;
}