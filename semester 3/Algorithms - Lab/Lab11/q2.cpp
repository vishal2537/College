#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector<pair<int, int>> graph[N];
vector<vector<int>> allpaths; // all potential paths present between two nodes
int hsh[N];
int adjmat[N][N];

void displayallpaths(vector<vector<int>> &v)
{
    for (auto vec : v)
    {
        for (auto it : vec)
        {
            cout << it << " ";
        }
        cout << endl;
    }
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

void clearhsh()
{
    for (int i = 0; i < N; i++)
        hsh[i] = 0;
}

void dfs(int vertex, int destination, int n, vector<int> &path)
{
    if (path.size() > 2 * n)
    {
        return;
    }
    // adding vertex to path
    path.push_back(vertex);
    if (vertex == destination)
    {
        allpaths.push_back(path);
    }
    for (auto child : graph[vertex])
    {
        dfs(child.first, destination, n, path);
    }

    // reverting changes -> removing vertex from path before exiting the vertex
    path.pop_back();
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
        adjmat[v1][v2] = wt;
    }
    cout << "Enter source : " << endl;
    int s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {   
        // i for destination node
        // cout<<"For destination "<<i<<" :"<<endl;
        //  finding all potential paths using dfs
        allpaths.clear();
        vector<int> path;
        dfs(s, i, n, path);

        // displayallpaths(allpaths);
        bool pathexists = false;
        int mincost = INT_MAX;
        vector<int> minpath;
        for (auto v : allpaths)
        {
            // working on a path from s to i
            clearhsh();
            bool cyclepresent = false;
            for (auto node : v)
            {
                hsh[node]++;
                if (hsh[node] >= 2)
                {
                    cyclepresent = true;
                    break;
                }
            }

            if (cyclepresent)
            {
                int cost = 0;
                pathexists = true;
                for (int j = 1; j < v.size(); j++)
                {
                    cost += adjmat[v[j - 1]][v[j]];
                }
                if (cost < mincost)
                {
                    mincost = cost;
                    minpath.clear();
                    minpath = v;
                }
            }
        }

        if (pathexists)
        {
            cout << "Shortest path between " << s << " and " << i << " containing cycle is : " << endl;
            display(minpath);
            cout << "Minimum cost is : " << mincost << endl;
        }
        else
        {
            cout << "NO PATH between " << s << " and " << i << " containing a cycle." << endl;
        }
    }
    return 0;
}

/*
input :
5 6
0 1 1
1 2 3
2 4 2
2 3 1
3 1 2
1 0 2
0

output ;
Shortest path between 0 and 0 containing cycle is :
0 -> 1 -> 0
Minimum cost is : 3
Shortest path between 0 and 1 containing cycle is :
0 -> 1 -> 0 -> 1
Minimum cost is : 4
Shortest path between 0 and 2 containing cycle is :
0 -> 1 -> 0 -> 1 -> 2
Minimum cost is : 7
Shortest path between 0 and 3 containing cycle is :
0 -> 1 -> 0 -> 1 -> 2 -> 3
Minimum cost is : 8
Shortest path between 0 and 4 containing cycle is :
0 -> 1 -> 0 -> 1 -> 2 -> 4
Minimum cost is : 9

*/
/*
input :
5 5
0 1 1
1 2 3
2 4 2
2 3 1
3 1 2
0

output :
NO PATH between 0 and 0 containing a cycle.
Shortest path between 0 and 1 containing cycle is :
0 -> 1 -> 2 -> 3 -> 1
Minimum cost is : 7
Shortest path between 0 and 2 containing cycle is :
0 -> 1 -> 2 -> 3 -> 1 -> 2
Minimum cost is : 10
Shortest path between 0 and 3 containing cycle is :
0 -> 1 -> 2 -> 3 -> 1 -> 2 -> 3
Minimum cost is : 11
Shortest path between 0 and 4 containing cycle is :
0 -> 1 -> 2 -> 3 -> 1 -> 2 -> 4
Minimum cost is : 12
*/