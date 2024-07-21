//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, -1);
        queue<int> q;
        q.push(0);
        vis[0] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                if (vis[it] == -1)
                {
                    vis[it] = !vis[node];
                }
                else if (vis[it] == vis[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.detectCycle(V, adj);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends