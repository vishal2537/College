#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v;
    int e;
    cin>>v>>e;
    int graph[v+1][v+1] ;

    for (int i = 0; i < v +1; i++)
    {
        for (int j = 0; j < v+1; j++)
        {
            graph[i][j]= 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u] =1;
    }
    cout<< " matrix : " <<endl;
    for (int i = 1; i < v +1; i++)
    {
        for (int j = 1; j < v+1; j++)
        {
            cout<<graph[i][j]<< " ";
        }
        cout<<endl;
    }

    vector<int>adj[v];
    for (int i = 0; i < v+1; i++)
    {
        for (int j = 0; j < v+1; j++)
        {
            if(graph[i][j] == 1 && i!=j)
            {
                adj[i].push_back(j);
                // adj[j].push_back(i);
            }
        }
        
    }

    cout<<" list :"<<endl;
    for (int i = 0; i < v+1; i++)
    {
        // cout <<  adj[i][] <<"--";
        cout<<i<<" : ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j] << " ";
        }
        cout<<endl;
    }
}

// 8
// 8
// 1 2
// 2 6
// 2 5
// 1 3
// 3 4
// 3 7
// 4 8
// 7 8