class DisjointSet
{
public:
    vector<int> size, parent;
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findUparent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUparent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if (ulp_u == ulp_v)
            return;

        else if (size[ulp_v] > size[ulp_u])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};
class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        // code here
        DisjointSet ds(n);
        int extracnt = 0;
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            if (ds.findUparent(u) == ds.findUparent(v))
                extracnt++;
            else
            {
                ds.unionBySize(u, v);
            }
        }

        int comp = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                comp++;
        }
        int count = comp - 1;
        if (extracnt >= count)
            return count;
        else
            return -1;
    }
};