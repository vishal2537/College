#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int start, vector<int> &ans, vector<int> &vis)
{
    ans.push_back(start);
    vis[start] = 1;
    for (auto it : adj[start])
        if (vis[it] != 1)
            dfs(adj, it, ans, vis);
}

void dfs2(vector<int> adj[], int start, vector<int> &vis)
{
    vis[start] = 1;
    for (auto it : adj[start])
        if (vis[it] != 1)
            dfs2(adj, it, vis);
}

void dfs1(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs1(it, st, vis, adj);
    }

    st.push(node);
}

void revdfs(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[it])
            revdfs(it, vis, transpose);
    }
}

int main()
{
    int n = 7, m = 8;
    vector<int> adj[n + 1];
    adj[1].push_back(3);
    adj[1].push_back(7);
    adj[2].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(4);
    adj[6].push_back(5);

    vector<int> transpose[n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
            transpose[it].push_back(i);
    }
    int flag = 0;

    int flag1 = 0;
    vector<int> ans;
    stack<int> st;
    vector<int> vis(n + 1, 0);
    vector<int> vis1(n + 1, 0);
    vector<int> visi(n + 1, 0);
    vector<int> vis2(n + 1, 0);
    dfs(adj, 1, ans, vis);
    dfs1(1, st, vis1, adj);
    if (find(vis.begin() + 1, vis.end(), 0) == vis.end())
    {
        vector<int> ans;
        dfs(transpose, 1, ans, visi);
    }
    else
        flag1 = 1;

    if (flag1 != 1 && find(visi.begin() + 1, visi.end(), 0) != visi.end())
        flag1 = 1;

    if (flag1 == 0)
        cout << "Graph is strongly connected" << endl;
    else
        cout << " Graph is not strongly conected" << endl;

    vector<int> undirected[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (auto it : adj[i])
        {
            undirected[i].push_back(it);
            undirected[it].push_back(i);
        }
    }
    int cnt = 0;
    vector<int> viss(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!viss[i])
        {
            cnt++;
            dfs(undirected, i, ans, viss);
        }
    }
    if (cnt == 1)
        cout << "weekly connected" << endl;
    else
        cout << " not weakly connected" << endl;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis2[node])
        {
            cout << "SCC : ";
            revdfs(node, vis2, transpose);
            cout << endl;
        }
    }

    int cntr = 0;
    vector<int> temp1(n + 1, 0);
    vector<vector<int>> ans1;
    for (int i = 1; i <= n; i++)
    {
        if (temp1[i] == 1)
            continue;
        cntr++;
        vector<int> varr(n + 1, 0);
        vector<int> temp;
        temp.push_back(i);
        dfs2(adj, i, varr);
        for (int j = 1; j <= n; j++)
        {
            if (j != i && varr[j] == 1)
            {
                vector<int> varr1(n + 1, 0);
                dfs2(adj, j, varr1);
                if (varr1[i] == 1)
                    temp.push_back(j);
            }
        }
        for (int k = 0; k < temp.size(); k++)
        {
            temp1[temp[k]] = 1;
        }
        ans1.push_back(temp);
    }

    for (auto it : ans1)
    {
        cout << "SCC : ";
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    cout << "\n Number of strongly connected components : ";
    cout << cntr << endl;

    return 0;
}