//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void dfs(int V, vector<int> &ls, vector<int> &vis, vector<int> adj[])
    {
        vis[V] = 1;
        ls.push_back(V);
        for (auto it : adj[V])
        {
            if (!vis[it])
            {
                dfs(it, ls, vis, adj);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int start = 0;
        vector<int> ls;
        vector<int> vis(V, 0);
        dfs(start, ls, vis, adj);
        return ls;
        // Code here
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends