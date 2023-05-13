#include <bits/stdc++.h>
using namespace std;

bool bellman_ford(int s, int n, vector<vector<int>> &graph)
{
    vector<int> dis(n, INT_MAX);
    dis[s] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : graph)
        {
            int v1 = edge[0], v2 = edge[1], wt = edge[2];
            if (dis[v1] != INT_MAX && dis[v1] + wt < dis[v2])
            {
                dis[v2] = dis[v1] + wt;
            }
        }
    }
    for (auto edge : graph)
    {
        int v1 = edge[0], v2 = edge[1], wt = edge[2];
        if (dis[v1] != INT_MAX && dis[v1] + wt < dis[v2])
        {
            return true;
        }
    }
    return false;
}

void display(vector<int> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        vector<int> temp(3);
        temp[0] = v1, temp[1] = v2, temp[2] = wt;
        graph.push_back(temp);
    }

    vector<int> soln;
    for (int i = 0; i < n; i++)
    {
        if (bellman_ford(i, n, graph))
        {
            soln.push_back(i);
        }
    }
    if (soln.size() == 0)
    {
        cout << "No such vertex exists (Graph does not contain a negative cycle)" << endl;
    }
    else
    {
        cout << "Edges from where negative cycle can be reached are : " << endl;
        display(soln);
    }

    return 0;
}

/*

input :
8 9
0 1 5
1 4 6
6 4 1
1 2 -3
2 3 -1
3 1 2
5 2 4
7 5 -2
5 7 -1

output :
0 1 2 3 5 7

*/