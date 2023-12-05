#include<bits/stdc++.h>
using namespace std;

struct node{
    int u,v,wt;
    node(int x,int y,int weight)
    {
        u=x;
        v=y;
        wt=weight;
    }
};

bool compare(node a,node b)
{
    return a.wt<b.wt;
}

int findparent(int u,vector<int>&parent)
{
    if(u==parent[u])
    {
        return u;
    }
    return parent[u] = findparent(parent[u],parent);
}

void unionnn(int u,int v,vector<int>&parent,vector<int>&rank)
{
    u=findparent(u,parent);
    v=findparent(v,parent);
    if(rank[u]<rank[v])
    {
        parent[u] =v;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[v] ++;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<node>edges;

    for (int i = 0; i < m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
        edges.push_back({v,u,wt});
    }

    sort(edges.begin(),edges.end(),compare);

    vector<int> rank(n,0);
    vector<int> parent(n,0);
    for (int i = 0; i <n ; i++)
    {
        parent[i] = i;
    }

    int mincost =0;
    vector<pair<int,int>> mst;

    for(auto it : edges)
    {
        if(findparent(it.v,parent) != findparent(it.u,parent))
        {
            mincost += it.wt;
            mst.push_back({it.u ,it.v});
            unionnn(it.u,it.v,parent,rank);
        }
    } 
    cout<<mincost<<endl;

    for (auto it: mst)
    {
        cout<<it.first << "--"<< it.second<<endl;
    }

    return 0;
}

// 7
// 9
// 1 4 1
// 1 5 4
// 1 2 2 
// 5 4 9
// 2 4 3
// 4 3 5
// 2 3 3
// 3 6 8 
// 2 6 7


// 5
// 6
// 0 1 2 
// 0 3 6
// 1 0 2
// 1 2 3
// 1 3 8 
// 1 4 5


// #include<bits/stdc++.h>
// using namespace std;

// struct node{
//     int u,v,wt;
//     node(int x,int y,int weight)
//     {
//         u=x;
//         v=y;
//         wt=weight;
//     }
// };

// bool compare(node a,node b)
// {
//     return a.wt<b.wt;
// }

// int findparent(int u,vector<int>&parent)
// {
//     if(u==parent[u])
//     {
//         return u;
//     }
//     return parent[u] = findparent(parent[u],parent);
// }

// void unionnn(int u,int v,vector<int>&parent,vector<int>&rank)
// {
//     u= findparent(u,parent);
//     v= findparent(v,parent);
//     if(rank[u]<rank[v])
//     {
//         parent[u] =v;
//     }
//     else if(rank[v] < rank[u])
//     {
//         parent[v] = u;
//     }
//     else
//     {
//         parent[v] = u;
//         rank[v] ++;
//     }
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     vector<node>edges;

//     for (int i = 0; i < m; i++)
//     {
//         int u,v,wt;
//         cin>>u>>v>>wt;
//         edges.push_back({u,v,wt});
//         edges.push_back({v,u,wt});

//     }

//     sort(edges.begin(),edges.end(),compare);
//     vector<int> rank(n,0);
//     vector<int> parent(n);
//     for (int i = 0; i <n ; i++)
//     {
//         parent[i] = i;
//     }

//     int mincost =0;
//     vector<pair<int,int>> mst;

//     for(auto it : edges)
//     {
//         if(findparent(it.v,parent) != findparent(it.u,parent))
//         {
//             mincost += it.wt;
//             mst.push_back({it.u ,it.v});
//             unionnn(it.u,it.v,parent,rank);
//         }
//     } 
//     cout<<mincost<<endl;

//     for (auto it: mst)
//     {
//         cout<<it.first << "--"<< it.second<<endl;
//     }

//     return 0;
// }

// // 6
// // 9
// // 1 4 1
// // 1 5 4
// // 1 2 2 
// // 5 4 9
// // 2 4 3
// // 4 3 5
// // 2 3 3
// // 3 6 8 
// // 2 6 7


// // 5
// // 6
// // 0 1 2 
// // 0 3 6
// // 1 0 2
// // 1 2 3
// // 1 3 8 
// // 1 4 5