#include <bits/stdc++.h>
using namespace std;

void bfs(int start, int vis[], vector<int> adj[], vector<int> &ls)
{

    vis[start] = 1;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int it = q.front();
        q.pop();

        ls.push_back(it);

        for (auto i : adj[it])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

signed main()
{

    int v, e;
    cout << "Enter the number of vertices" << endl;
    cin >> v;

    cout << "Enter the number of edges" << endl;
    cin >> e;

    vector<int> adj[v + 1];

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans;
    int st;
    cout << "Enter the starting node for bfs" << endl;
    cin >> st;

    int vis[v] = {0};
    bfs(st, vis, adj, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}