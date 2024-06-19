#include <bits/stdc++.h>
using namespace std;

// a bipartite graph is a graph in which no two adjacent nodes have the same colour if we colour every node with two distinct colours
bool check(int start, int V, vector<int> adj[], int col[])

{

    // this function basically checks for connected components in the graph

    // we will use two colours 0 & 1

    queue<int> q;

    q.push(start);
    col[start] = 0;

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();

        for (auto it : adj[fr])
        {
            if (col[it] == -1)
            {
                col[it] = !col[fr];
                q.push(it);
            }
            else if (col[it] == col[fr])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    // we shall use bfs here
    int col[V];
    for (int i = 0; i < V; i++)
    {
        col[i] = -1;
    }

    for (int i = 0; i < V; i++)
    {
        if (col[i] == -1)
        {
            if (check(i, V, adj, col) == false)
                return false;
        }
    }

    return true;
}

signed main()
{
}