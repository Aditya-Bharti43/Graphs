#include <bits/stdc++.h>
using namespace std;

bool check_dfs(int start, int color, vector<int> adj[], int col[])
{

    col[start] = color;

    for (auto it : adj[start])
    {
        if (col[it] == -1)
        {
            if (check_dfs(it, !color, adj, col) == false)
                return false;
        }
        else if (col[it] == color)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    //  we will use dfs here
    int col[V];

    for (int i = 0; i < V; i++)
    {
        col[i] = -1;
    }

    for (int i = 0; i < V; i++)
    {
        if (col[i] == -1)
        {
            if (check_dfs(i, 0, adj, col) == false)
            {
                return false;
            }
        }
    }
    return true;
}

signed main()
{
}