#include <bits/stdc++.h>
using namepsace std;

bool dfs_check(int node, vector<int> adj[], int vis[], int pathvis[])
{

    vis[node] = 1;
    pathvis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs_check(it, adj, vis, pathvis) == true)
                return true;
        }
        // if the node has been preciously visited but it has to be on the same path
        else if (pathvis[it])
        {
            return true;
        }
    }

    pathvis[node] = 0;
    return false;
}

bool cycle_in_directed_graph(int V, vector<int> adj[])

{
    int vis[V] = {0};
    int pathvis[V] = {0};

    //    calling component wise

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs_check(i, adj, vis, pathvis) == true)
                return true;
        }
    }

    return false;
}

signed main()
{
}