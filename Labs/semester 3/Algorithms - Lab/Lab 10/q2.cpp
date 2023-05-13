#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(vector<int> &hT, pair<int,int>ne)
{
  int size = hT.size();
  int largest = ne.second;
  int l = 2 * ne.second + 1;
  int r = 2 * ne.second + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  if (largest != ne.second)
  {
    swap(&hT[ne.second], &hT[largest]);
    heapify(hT, largest);
  }
}

void insert(vector<pair<int,int>> &hT, pair<int,int>newNum)
{
  int size = hT.size();
  if (size == 0)
  {
    hT.push_back(newNum);
  }
  else
  {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(hT, i);
    }
  }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int source;
    cin>>source;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int>parent(n);
    vector<int>key(n);
    bool temp[n];

    for (int i = 0; i < n; i++)
    {
        key[i]=INT_MAX;
        temp[i] = false;
        parent[i] =-1;
    }

    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<pair<int,int>>minheap;
    key[source]=0;
    parent[source]=-1;
    // minheap.push_back({0,0});
    insert(minheap ,{0 , 0});

    while (!minheap.empty())
    {
        int u = pq.top().second;
        pq.pop();
        temp[u] = true;
        for(auto it : adj[u])
        {
            int v= it.first;
            int wt=it.second;
            if(temp[v]==false && wt < key[v])
            {
                key[v] = wt;
                parent[v]=u;
                // minheap.push_back({key[v],v});
                insert(minheap ,{key[v] , v});
            }
        }
    }
    int mst =0;
    for (int i = 0; i < n; i++)
    {
        cout<<" { "<<i<<"  "<<parent[i] <<" } - "<< key[i] <<endl;
        // mst+= key[i];
    }
    cout<<mst;
}