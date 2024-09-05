class Solution
{
public:
    vector<int> toposort(vector<int> adj[], int k)
    {
        vector<int> indegree(k, 0);
        for (int i = 0; i < k; i++)
        {
            for (int j : adj[i])
            {
                indegree[j]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < k; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
    string findOrder(string dict[], int n, int k)
    {
        // code here
        vector<int> adj[k];
        for (int i = 0; i < n - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int par = 0; par < len; par++)
            {
                if (s1[par] != s2[par])
                {
                    adj[s1[par] - 'a'].push_back(s2[par] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = toposort(adj, k);
        string ans = "";
        for (auto it : topo)
        {
            ans += (it + 'a');
        }
        return ans;
    }
};