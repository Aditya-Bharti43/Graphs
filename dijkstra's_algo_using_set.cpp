#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  // we will use the set data structure to implement the dijkstra algorithm

  vector<int> dist(V);

  for (int i = 0; i < V; i++)
  {
    dist[i] = 1e9;
  }

  dist[S] = 0;

  set<pair<int, int>> st;

  //   {distance,node}

  st.insert({0, S});

  while (!st.empty())
  {
    // the first elemnt has the least distance
    auto it = *(st.begin());

    int dis = it.first;
    int node = it.second;

    st.erase(it);

    for (auto it : adj[node])
    {
      int adjnode = it[0];
      int edw = it[1];

      if (dis + edw < dist[adjnode])
      {
        dist[adjnode] = dis + edw;
        st.insert({dist[adjnode], adjnode});
      }
    }
  }

  return dist;
}

signed main()
{
}