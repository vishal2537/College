#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int index;
    int parent;
    struct Node *next;
    struct Node *prev;
};

void insert(struct Node **head, int data, int index)
{

    if (*head == NULL)
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->index = index;
        node->parent = data;
        node->next = NULL;
        node->prev = NULL;
        *head = node;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->index = index;
        node->parent = data;
        node->next = NULL;
        node->prev = temp;
        temp->next = node;
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;
    struct Node *second = head;
    while (temp != NULL)
    {
        cout << temp->index << " " << temp->parent << endl;
        temp = temp->next;
    }
}
int findpar(int node, struct Node *head)
{
    struct Node *temp = head;
    int parent;
    while (temp)
    {
        bool flag = false;
        if (node == temp->parent && node == temp->index)
        {
            return node;
            break;
        }
        else if (node != temp->parent && node == temp->index)
        {
            parent = temp->parent;
            if (temp->parent > temp->index)
            {
                while (temp)
                {
                    if (parent == temp->index)
                    {
                        break;
                    }
                    temp = temp->next;
                }
                flag = true;
                node = temp->index;
            }
            else
            {
                while (temp)
                {
                    if (parent == temp->index)
                    {
                        break;
                    }
                    temp = temp->prev;
                }
                node = temp->index;
                flag = true;
            }
        }
        if (flag && parent == temp->index && temp->parent == parent)
        {
            return temp->parent;
            break;
        }
        if (!flag)
        {
            temp = temp->next;
        }
    }
    return node; // nothing (-1)
}
int findrank(int node, struct Node *rank)
{
    struct Node *temp = rank;
    while (temp)
    {
        if (node == temp->index)
        {
            return temp->parent;
        }
        temp = temp->next;
    }
    return -1;
}
void makeparent(int node, int ind, struct Node *parent)
{
    struct Node *temp = parent;
    while (temp)
    {
        if (ind == temp->index)
        {
            temp->parent = node;
            break;
        }
        temp = temp->next;
    }
}
void updateRank(int ind, struct Node *rank)
{
    struct Node *temp = rank;
    while (temp)
    {
        if (ind == temp->index)
        {
            temp->parent += 1;
            break;
        }
        temp = temp->next;
    }
}
void Union(int u, int v, struct Node *parent, struct Node *rank)
{
    u = findpar(u, parent);
    v = findpar(v, parent);

    if (findrank(u, rank) < findrank(v, rank))
    {
        makeparent(v, u, parent);
    }
    else if (findrank(u, rank) > findrank(v, rank))
    {
        makeparent(u, v, parent);
    }
    else
    {
        makeparent(u, v, parent);
        updateRank(u, rank);
    }
}

int kruskal(struct Node *parent, struct Node *rank, vector<pair<int, pair<int, int>>> adj, vector<pair<int, int>> &mst)
{
    int cost = 0;
    for (auto it : adj)
    {
        if (findpar((it.second).first, parent) != findpar((it.second).second, parent))
        {
            cost += it.first;
            Union((it.second).first, (it.second).second, parent, rank);
            mst.push_back({(it.second).first, (it.second).second});
        }
    }
    return cost;
}

int main()
{
    cout << "Enter number of Vertices  and Edges" << endl;
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> adj;
    cout << "Enter all edges : " << endl;

    for (int i = 0; i < m; i++)
    {
        int v1, v2, v3;
        cin >> v1 >> v2 >> v3;
        adj.push_back({v3, {v1, v2}});
    }
    sort(adj.begin(), adj.end());

    struct Node *parent = NULL;
    struct Node *rank = NULL;

    for (int i = 0; i < n; ++i)
    {
        insert(&parent, i, i);
        insert(&rank, 0, i);
    }
    // cout << findpar(n, parent) << endl;
    vector<pair<int, int>> mst;
    cout << "The cost of minimum spanning tree is : ";
    cout << kruskal(parent, rank, adj, mst) << endl;
    cout << "The spanning tree is : " << endl;
    for (auto it : mst)
    {
        cout << it.first << " " << it.second << endl;
    }
}