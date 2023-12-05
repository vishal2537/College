#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],int visited[])
{
    visited[node] =1;
    for (auto it: adj[node])
    {
        cout<< it << " "; 
        if(!visited[it] )
        {
            dfs(it,adj,visited);
        }
    }
}

int numberofweaklyconnectedcomponent(vector<int> adj[],int v ,int start)
{
    int count =0;
    int visited[v +1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            cout<< "weakly connected graph : ";
            count+=1;
            dfs(i,adj,visited);
        }
    }
    return count;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n ];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cout << "please give starting node start node : ";
    cin >> s;
    // cout<<"given graph : "<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<i<<" : ";
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout<<adj[i][j] << " ";
    //     }
    //      cout<<endl;
    // }
    int x=numberofweaklyconnectedcomponent(adj,n ,s);
    cout<<endl;
    if(x>1)
    {
        cout<<"graph is not weakly connected "<<endl;
    }
    else{
        cout<<"graph is weakly connected "<<endl;   
    }
    // cout<<"number of weakly connected graph : " << x<<endl;
    return 0;
}


// 5
// 3
// 0 1 
// 0 2
// 3 4