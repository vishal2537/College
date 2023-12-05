#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<pair<int, int>> graph[N];
vector<int> path;

vector<int> dijkstra(int s, int n, vector<int> &par, vector<pair<int, int>> graph[])
{
    vector<int> dis(n, INT_MAX);
    dis[s] = 0;
    par[s] = s;
    set<pair<int, int>> st;
    st.insert({0, s});

    while (!st.empty())
    {
        auto it = st.begin();
        int node = it->second;
        int d = it->first;
        st.erase(it);

        for (auto child : graph[node])
        {
            int adjnode = child.first;
            int wt = child.second;
            if (d + wt < dis[adjnode])
            {
                dis[adjnode] = d + wt;
                st.insert({dis[adjnode], adjnode});
                par[adjnode] = node;
            }
        }
    }
    return dis;
}

void createpath(int s, int node, vector<int> &par)
{
    path.push_back(node);
    if (node == s)
    {
        reverse(path.begin(), path.end());
        return;
    }
    createpath(s, par[node], par);
}

void display(vector<int> &v)
{
    int len = v.size();
    for (int i = 0; i < len - 1; i++)
    {
        cout << v[i] << " -> ";
    }
    cout << v[len - 1] << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back({v2, wt});
    }

    vector<int> minidistance;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        vector<int> par(n);
        for (int j = 0; j < n; j++)
        {
            par[j] = j;
        }
        minidistance = dijkstra(i, n, par, graph);
        for (int j = 0; j < n; j++)
        {
            path.clear();
            if (minidistance[j] != INT_MAX)
            {
                createpath(i, j, par);
                if (path.size() == 3)
                {
                    flag = true;
                    display(path);
                }
            }
        }
    }

    if (!flag)
    {
        cout << "NO SHORTEST PATH OF LENGTH TWO" << endl;
    }

    return 0;
}

/*
input :
7 12
0 1 5
0 2 3
2 0 2
2 1 4
2 3 1
3 1 1
2 4 7
4 2 1
4 5 2
3 5 3
3 6 1
6 5 1

output :   
0 -> 2 -> 3
0 -> 2 -> 4
2 -> 3 -> 1
2 -> 3 -> 6
3 -> 6 -> 5
4 -> 2 -> 0
4 -> 2 -> 3

*/