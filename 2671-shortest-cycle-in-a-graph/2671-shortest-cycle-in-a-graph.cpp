class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // 1) Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int result = INT_MAX;
        vector<int> dist(n);

        // 2) For each edge (u,v), temporarily “remove” it and BFS from u to v
        for (auto &e : edges) {
            int u = e[0], v = e[1];

            // Reset distances
            fill(dist.begin(), dist.end(), -1);

            queue<int> q;
            dist[u] = 0;
            q.push(u);

            // Standard BFS, but skip over the removed edge (u–v)
            while (!q.empty() && dist[v] == -1) {
                int x = q.front(); q.pop();
                for (int y : adj[x]) {
                    // If this is the edge we're “removing”, skip it
                    if ((x == u && y == v) || (x == v && y == u))
                        continue;
                    if (dist[y] == -1) {
                        dist[y] = dist[x] + 1;
                        q.push(y);
                    }
                }
            }

            // If v is reachable, we found a cycle of length = (path u→v) + this edge
            if (dist[v] != -1) {
                result = min(result, dist[v] + 1);
            }
        }

        return (result == INT_MAX ? -1 : result);
    }
};
