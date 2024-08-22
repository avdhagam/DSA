class Solution
{
public:
    bool dfs(int i, int col, vector<int> &color, vector<int> adj[])
    {
        color[i] = col;
        for (auto it : adj[i])
        {
            if (color[it] == -1)
            {
                if (dfs(it, !col, color, adj) == false)
                    return false;
            }
            else if (color[it] == col)
            {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> adj[graph.size()];
        for (int i = 0; i < graph.size(); i++)
        {
            for (auto it : graph[i])
            {
                adj[i].push_back(it);
            }
        }

        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, color, adj) == false)
                    return false;
            }
        }
        return true;
    }
};