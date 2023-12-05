#include<bits/stdc++.h>
using namespace std;

void dfs(int node,stack<int>&st,vector<int>&visited,vector<int>adj[])
{
    visited[node] =1;
    for (auto it : adj[node])
    {
        if(!visited[it])
        {
            dfs(it,st,visited,adj);
        }
    }
    st.push(node);
}

void reversedfs(int node,vector<int>&visited,vector<int>transpose[])
{
    cout<<node<< " ";
    visited[node]=1 ;
    for(auto it: transpose[node])
    {
        if(!visited[it])
        {
            reversedfs(it,visited,transpose);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n +1];

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> visited(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i,st,visited,adj);
        }
    }
    
    vector<int> transpose[n+1];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
        for (auto it: adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    cout<<"\ntranspose : ";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <transpose[i].size(); i++)
        {
            cout<<i <<" "<<transpose[i][j]<< endl;
        }
        cout<<endl;
    }
    
    int count=0;

    while(!st.empty())
    {
        int node =st.top();
        st.pop();
        if(!visited[node])
        {
            count++;
            cout << " strongly connected component are : ";
            reversedfs(node, visited ,transpose);
            cout<<endl;
        }
    }

    cout<<"number of connected component : " << count<<endl;    
    return 0;
}




// 6
// 7
// 0 2 
// 1 0 
// 2 1
// 2 4
// 4 3
// 3 5
// 5 4

// 4
// 5
// 0 1
// 1 2
// 2 3
// 0 4
// 4 0