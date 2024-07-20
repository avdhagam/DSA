void dfs(int i, int V, vector<int> adj[], vector<int> vis, stack<int> st)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(it, V, adj, vis, st);
        }
    }
    st.push(i);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, V, adj, vis, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}