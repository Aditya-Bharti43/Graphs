#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find_ultimate_parent(int node)
    {
        if (node == parent[node])
            return node;

        // backtracking for path compression

        return parent[node] = find_ultimate_parent(parent[node]);
    }

    void union_by_rank(int u, int v)
    {
        int ulp_u = find_ultimate_parent(u);
        int ulp_v = find_ultimate_parent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            // smaller gets attached to larger
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

signed main()
{

    DisjointSet ds(7);
    ds.union_by_rank(1, 2);
    ds.union_by_rank(2, 3);
    ds.union_by_rank(4, 5);
    ds.union_by_rank(6, 7);
    ds.union_by_rank(5, 6);

    if (ds.find_ultimate_parent(3) == ds.find_ultimate_parent(7))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
        ds.union_by_rank(3, 7);

        cout << ds.find_ultimate_parent(3) << endl;
        cout << ds.find_ultimate_parent(7) << endl;
    }
}