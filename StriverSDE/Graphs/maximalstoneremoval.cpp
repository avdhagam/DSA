vector<int> parent, size;
class DisjointSet
{
public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
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

    void unionbysize(int u, int v)
    {
        int ulpu = findUparent(u);
        int ulpv = findUparent(v);

        if (ulpu == ulpv)
            return;

        if (size[ulpu] > size[ulpv])
        {
            size[ulpu] += size[ulpv];
            parent[ulpv] = ulpu;
        }
        else
        {
            size[ulpv] += size[ulpu];
            parent[ulpu] = ulpv;
        }
    }
};

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        // Code here
        int maxrow = 0;
        int maxcol = 0;
        for (auto it : stones)
        {
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        DisjointSet ds(maxrow + maxcol + 1);

        unordered_map<int, int> mp;

        for (auto it : stones)
        {
            int row = it[0];
            int col = it[1] + maxrow + 1;

            ds.unionbysize(row, col);

            mp[row] = 1;
            mp[col] = 1;
        }

        int cnt = 0;
        for (auto i : mp)
        {
            if (ds.findUparent(i.first) == i.first)
                cnt++;
        }

        return n - cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int i = 0; i < 2; ++i)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends