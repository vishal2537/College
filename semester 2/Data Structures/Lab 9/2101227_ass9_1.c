#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int count1 = 0;
void chaining(struct node *H[], int data, int index)
{
    if (H[index] == NULL)
    {
        H[index] = newnode(data);
        return;
    }
    struct node *temp = H[index], *prev = NULL;
    while (temp && temp->data < data)
    {
        prev = temp;
        temp = temp->next;
    }
    struct node *t = newnode(data);
    t->next = temp;
    if (prev == NULL)
        H[index] = t;
    else
        prev->next = t;
    count1++;
}

int hash(int key, int size)
{
    return key % size;
}

void chain_insert(struct node *H[], int key, int size)
{
    int index = hash(key, size);
    chaining(H, key, index);
}

void display_chain(struct node *temp[], int n)
{
    printf("\nusing chaining :\n");
    for (int i = 0; i < n; i++)
    {
        printf(" [  %d   , ", i);
        struct node *t = temp[i];
        while (t)
        {
            printf(" %d --> ", t->data);
            t = t->next;
        }
        printf("    ]\n");
    }
    printf("\n");
}

int count2 = 0;
int linear_probing(int H[], int key, int size)
{
    int index = hash(key, size);
    int i = 0;
    while (H[(index + i) % size] != 0)
        i++;
    count2++;
    return (index + i) % size;
}

void linear_probing_insert(int H[], int key, int size)
{
    int index = hash(key, size);
    if (H[index] != 0)
        index = linear_probing(H, key, size);

    H[index] = key;
}

// int Search(int H[], int key, int size)
// {
//     int index = hash(key, size);

//     int i = 0;
//     while (H[(index + i) % size] != key)
//         i++;

//     return (index + i) % size;
// }

void linear_probing_display(int ht[], int size)
{
    int i = 0;
    printf("\n\nusing linear probing :\n");
    for (i = 0; i < size; i++)
    {
        if (ht[i] != 0)
            printf(" [  %d  ,   %d  ] \n", i, ht[i]);
        else
            printf(" [  %d  ,   0  ]  \n");
    }

    printf("\n");
}

int main()
{
    int size;
    printf("\nenter size of table {only prime number} : ");

    scanf("%d", &size);
    struct node *h[size];
    int ht[size];

    int i;

    for (i = 0; i < size; i++)
        ht[i] = 0;

    struct node *temp;
    srand(time(0));
    for (i = 0; i < size; i++)
        h[i] = NULL;
    printf("\nelement are : ");

    for (i = 0; i < size; i++)
    {
        int x = rand() % size;
        printf("%d ");
        chain_insert(h, x, size);
        linear_probing_insert(ht, x, size);
    }

    linear_probing_display(ht, size);
    display_chain(h, size);
    printf("\nnumber of collision in chaining : %d \nnumber of collision in linear probing :%d\n", count1, count2);

    return 0;
}