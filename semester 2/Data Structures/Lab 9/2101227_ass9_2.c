#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    int index1;
    int index2;
    struct node *next;
};

struct keynode
{
    int data;
    int index1;
    int index2;
};

struct node *newnode(struct keynode *key, int i)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key[i].data;
    temp->index1 = key[i].index1;
    temp->index2 = key[i].index2;
    temp->next = NULL;
    return temp;
}

int count1 = 0;
void sorted_chain_insert(struct node *H[], int indx, struct keynode *key, int i)
{
    if (H[indx] == NULL)
    {
        H[indx] = newnode(key, i);
        return;
    }
    int d = 1;
    struct node *temp = H[indx], *prev = NULL;
    while (temp && temp->data < key[i].data)
    {
        prev = temp;
        temp = temp->next;
        count1++;
        d = 0;
    }
    struct node *t = newnode(key, i);
    t->next = temp;
    if (prev == NULL)
        H[indx] = t;
    else
        prev->next = t;
    if (d)
        count1++;
}

int count2 = 0;
int lhash(struct keynode *ht, int n, int key)
{
    int i = abs(key) % n;
    if (ht[i].data != INT_MIN)
    {
        while (ht[i].data != INT_MIN)
        {
            count2++;
            i = (i + 1) % n;
        }
        return i;
    }
    return i;
}

int hash(int n, int key)
{
    return abs(key) % n;
}

void subarray_sum(int arr[], struct keynode *subarraysum, int n)
{
    int sb[n];
    for (int i = 1; i <= n; i++)
    {
        sb[i] = sb[i - 1] + arr[i - 1];
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            subarraysum[k].data = sb[j] - sb[i];
            subarraysum[k].index1 = i;
            subarraysum[k].index2 = j - 1;
            k++;
        }
    }
}

void insert(struct keynode *h, struct node *H[], struct keynode *subarraysum, int m)
{
    for (int i = 0; i < m; i++)
    {
        int key = subarraysum[i].data;
        int idx1 = lhash(h, m, key);
        h[idx1] = subarraysum[i];
        int idx2 = hash(m, key);
        sorted_chain_insert(H, idx2, subarraysum, i);
    }
}

void display_chain(struct node *temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[  %d   ] ---> ", i);
        struct node *t = temp[i];
        while (t)
        {
            printf("%d  ", t->data);
            t = t->next;
        }
        printf("\n");
    }
    printf("\n");
}

void display_arr(struct keynode *h, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[   %d  ]=  %d  \n", i, h[i].data);
    }
}

int linear_probing_search(struct keynode *h, int m, int key)
{
    int indx = hash(m, key);
    int x=m;
    while (h[indx].data != key && h[indx].data != INT_MIN && x)
    {
        indx = (indx + 1) % m;
        x--;
        // printf("not present");
    }
    if (h[indx].data == key)
        return indx;
    else
        return -1;
}

int chaining_search(struct node *H[], int m, int key)
{
    int indx = hash(m, key);
    int x=m;
    while (H[indx] != NULL && H[indx]->data <= key && H[indx]->data != key && x)
    {
        H[indx] = H[indx]->next;
        x--;
    }

    if (H[indx] !=NULL && H[indx]->data == key)
        return indx;
    else
        return -1;
}

int main()
{
    while (1)
    {
        printf("1: play the game :  \n2: leave the game : \n");
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            count1 = 0;
            count2 = 0;
            printf("for PLAYER A  : \nenter size :  \n");
            int n;
            scanf("%d", &n);
            printf("\nenter elements : \n");
            int arr[n];
            int m = n * (n + 1) / 2;
            struct node *H[m];
            struct keynode h[m];
            struct keynode subarraysum[m];
            for (int i = 0; i < m; i++)
            {
                H[i] = NULL;
                h[i].data = INT_MIN;
            }
            for (int i = 0; i < n; i++)
            {
                int x;
                scanf("%d", &x);
                arr[i] = x;
            }
            subarray_sum(arr, subarraysum, n);
            insert(h, H, subarraysum, m);
            printf("for PLAYER B : \n");
            int y;
            scanf("%d", &y);
            int s1 = linear_probing_search(h, m, y);
            int s2 = chaining_search(H, m, y);
            printf("linear hash table result  with collisions %d\n", count2);
            if (s1 != -1)
            {
                printf("congratulations !! B wins\n");
                printf("subarray found: ");
                for (int i = h[s1].index1; i <= h[s1].index2; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            else
                printf("congratulations !! A wins\n");
            printf("chain hash table result with collisions %d\n", count1);
            if (s2 != -1)
            {
                printf("B wins\n");
                printf("subarray found: ");
                for (int i = H[s2]->index1; i <= H[s2]->index2; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            else
                printf("A wins\n");
            printf("1:print hash table \n2: main menu\n");
            int t2;
            scanf("%d", &t2);
            if (t2 == 1)
            {
                printf("linear hash table: \n");
                display_arr(h, m);
                printf("chain hash table ");
                display_chain(H, m);
            }
        }
        else if (t == 2)
            return 0;
        else
            printf("enter another num\n");
    }
}