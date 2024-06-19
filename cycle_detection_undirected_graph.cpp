#include <bits/stdc++.h>
using namespace std;

bool detect_cycle(int src, vector<int> adj[], int vis[])
{
  vis[src] = 1;
  queue<pair<int, int>> q;
  // /putting the second entity as parent of the first one in the queue

  q.push({src, -1});

  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;

    q.pop();

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        vis[it] = 1;
        q.push({it, node});
      }
      else if (parent != it)
      {
        // it means that it is already visited by some other parent
        return true;
      }
    }
  }

  return false;
}

// function which detects cycle in undirected graph

bool isCycle(int V, vector<int> adj[])
{

  int vis[v] = {0};

  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      if (detect_cycle(i, adj, vis))
        return true;
    }
  }

  return false;
}

signed main()

{
}