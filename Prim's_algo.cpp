#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // we use priority queue here

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // {wt,node}

    vector<int> vis(V, 0);

    //   we can start from any node ,so i am starting from node 0

    pq.push({0, 0});
    int mst_sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if (!vis[node])
        {
            vis[node] = 1;
            mst_sum += wt;
        }
        else
        {
            continue;
        }

        for (auto it : adj[node])
        {
            int adjnode = it[0];
            int edw = it[1];

            if (!vis[adjnode])
            {
                pq.push({edw, adjnode});
            }
        }
    }
    return mst_sum;
}

signed main()
{
}