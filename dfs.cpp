#include <bits/stdc++.h>
#include <vector>
using namespace std;

// dfs function

void dfs(int start, vector<int> adj[], vector<int> &ls, int vis[])
{

    vis[start] = 1;

    ls.push_back(start);

    for (auto it : adj[start])
    {
        if (!vis[it])
        {
            // ls.push_back(it);
            dfs(it, adj, ls, vis);
            vis[it] = 1;
        }
    }
}

signed main()
{

    // creating adjacency list for storing the graph

    int v, e;
    cout << "Enter the the number of vertices" << endl;
    cin >> v;
    cout << "Enter the number of edges" << endl;
    cin >> e;

    vector<int> adj[v + 1];
    int x, y;

    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int st;
    cout << "Enter the start node" << endl;
    cin >> st;

    vector<int> ans;
    int vis[v] = {0};

    dfs(st, adj, ans, vis);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
