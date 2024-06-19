#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)

{
    // Code here
    vector<int> dist(V);

    for (int i = 0; i < V; i++)
        dist[i] = 1e9;

    dist[S] = 0;
    // we will use priority queue here

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //   the above priority queue is initialised with pair<int,int> storing {weight,node}
    //  and custom comparator function greater<pair<>int,int>

    // Given the source node as S

    // {distance,node}

    pq.push({0, S});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for (auto it : adj[node])
        {
            int adjnode = it[0];
            int edw = it[1];

            if (dis + edw < dist[adjnode])
            {
                // update the new distance
                dist[adjnode] = dis + edw;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    return dist;
}

signed main()
{
}