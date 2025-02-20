#include <bits/stdc++.h>

using namespace std;

// the logic is :if the graph produces a toplogical sort having less than the number of vertices in the graph then there is a cycle present int the graph

bool isCycle(int V, vector<int> adj[])
{

    int indegree[V] = {0};

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (topo.size() != V)
        return true;

    return false;
}

signed main()

{
}