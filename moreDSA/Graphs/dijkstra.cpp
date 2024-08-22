class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            dist[node] = dis;
            for (auto i : adj[node])
            {
                if (dis + i[1] < dist[i[0]])
                {
                    dist[i[0]] = dis + i[1];
                    pq.push({dis + i[1], i[0]});
                }
            }
        }
        return dist;
    }