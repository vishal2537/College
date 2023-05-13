#include <bits/stdc++.h>
using namespace std;
int j=1;
void dfs(int node,vector<int>adj[],int visited[],vector<int>&ans)
{
    visited[node] =1;
    for (auto it: adj[node])
    {
        ans[it] =j;
        cout<< it << " "; 
        if(!visited[it] )
        {
            dfs(it,adj,visited,ans);
            if(ans[it] == j){
                j++;
            }
        }
    }
}

int number_of_connected_component(vector<int> adj[],int v ,int start,vector<int>&ans)
{
    int count =0;
    int visited[v ];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            cout<< " graph : ";
            count+=1;
            dfs(i,adj,visited,ans);
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
    cout<<"given graph : "<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j] << " ";
        }
         cout<<endl;
    }
    vector<int>ans(n,0);
    int x=number_of_connected_component(adj,n ,s ,ans);
    cout<<endl;
    cout<<"number of graph : " << x<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }

    cout<<"\nenter vertex to check :  ";
    int a , b;
    cout<<"\nenter vertex : ";
    cin>>a>>b;
    if(ans[a] == ans[b])
    {
        cout<< "in same component "<< endl;
    }
    else{
        cout<<"in different component "<<endl;
    }


    return 0;
}


// 8
// 5
// 0 1 
// 1 2
// 3 4
// 4 5
// 6 7