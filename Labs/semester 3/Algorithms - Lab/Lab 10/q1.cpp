
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int parent[n];
    int key[n];
    bool mstset[n];

    for (int i = 0; i < n; i++){
        key[i] = INT_MAX;
        mstset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        int minimum = INT_MAX;
        int u;
        for (int v = 0; v < n; v++)
        {
            if (mstset[v] == false && key[v] < minimum){
                minimum = key[v];
                u = v;
            }
        }
        mstset[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstset[v] == false && weight < key[v]){
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

   for (int i = 1; i < n; i++)
    {
        // cout<<parent[i] <<" - "<< key[i] << " - "<< mstset[i] << " - " << i <<endl;
        cout<<parent[i] <<" - "<< key[i] << " - "<< " - " << i <<endl;
    }
    return 0;
}



// 5
// 6
// 0 1 2 
// 0 3 6
// 1 3 8 
// 1 4 5
// 1 2 3
// 4 2 7