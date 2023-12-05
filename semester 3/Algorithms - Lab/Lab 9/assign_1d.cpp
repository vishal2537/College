#include<bits/stdc++.h>
using namespace std;

int  main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v+1];

    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    
    for (int i = 0; i < v+1; i++)
    {
        // cout <<  adj[i][0] <<"-->";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout<<adj[i][j] << " ";
        }
        cout<<endl;
    }

    int graph[v+1][v+1] = {0} ;

    // for (int i = 0; i < v +1; i++)
    // {
    //     for (int j = 0; j < v+1; j++)
    //     {
    //         graph[i][j]= 0;
    //     }
    // }

    for (int i = 0; i < v+1; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            // cout<<adj[i][j] << " ";
            graph[i][adj[i][j]] =1;
            // graph[adj[i][j]][i] =1;
        }
        // cout<<endl;
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
