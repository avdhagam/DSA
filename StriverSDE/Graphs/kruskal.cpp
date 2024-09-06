class Solution
{
    class DisjointSet
    {
        vector<int> size, parent;

    public:
        DisjointSet(int n)
        {
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }

        int findUparent(int n)
        {
            if (parent[n] == n)
                return n;

            return parent[n] = findUparent(parent[n]);
        }

        void UnionBySize(int u, int v)
        {
            int ulp_u = findUparent(u);
            int ulp_v = findUparent(v);
            if (ulp_u == ulp_v)
                return;
            if (size[ulp_u] > size[ulp_v])
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
    };

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjnode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {adjnode, node}});
            }
        }

        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mswt = 0;
        for (auto i : edges)
        {
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;

            if (ds.findUparent(u) != ds.findUparent(v))
            {
                mswt += wt;
                ds.UnionBySize(u, v);
            }
        }
        return mswt;
    }
};