class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> vis(V, 0);
        q.push(0);
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                }
            }
        }
        return ans;
        // Code here
    }
};