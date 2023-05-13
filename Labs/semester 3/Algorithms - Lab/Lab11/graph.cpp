#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int adjmatrix[n][n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjmatrix[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adjmatrix[u][v]=1;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< adjmatrix[i][j] << " ";
        }
        cout<<endl;
    }

}