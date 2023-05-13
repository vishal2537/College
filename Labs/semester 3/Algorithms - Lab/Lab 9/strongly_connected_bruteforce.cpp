#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, vector<int> &visited)
{
    // cout<<node<< " ";
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(adj,it, visited);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int count =0;
    vector<int> temp1(n + 1, 0);
    vector<vector<int>> ans;
    for (int i = 0; i <= n; i++)
    {
        if (temp1[i] == 1)
            continue;
        vector<int> visited2(n + 1, 0);
        vector<int> temp;
        temp.push_back(i);
        dfs(adj, i, visited2);
        count++;
        for (int j = 0; j <= n; j++)
        {
            if (j != i && visited2[j] == 1)
            {
                vector<int> visited(n + 1, 0);
                dfs(adj, j, visited);
                if (visited[i] == 1)
                    temp.push_back(j);
            }
        }
        for (int k = 0; k < temp.size(); k++)
        {
            temp1[temp[k]] = 1;
        }
        ans.push_back(temp);
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <=ans[i].si; j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"strongly connected components : "<<endl;
    for (auto it:ans)
    {
        for(auto it1:it)
        {
            cout << it1<<" ";
        }
        cout<<endl;
    }
    cout<<" count : "<<count;
    
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