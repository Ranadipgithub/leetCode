class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(int node, int n, vector<int>& dist, unordered_map<int, vector<int>>& graph, vector<int>& dp) {
        if (node == n) return 1;
        if (dp[node] != -1) return dp[node];

        int ways = 0;
        for (int ngbr : graph[node]) {
            if (dist[ngbr] < dist[node]) {
                ways = (ways + dfs(ngbr, n, dist, graph, dp)) % MOD;
            }
        }

        return dp[node] = ways;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[n] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, n});
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        unordered_map<int, vector<int>> graph;
        for (int u = 1; u <= n; ++u) {
            for (auto& [v, w] : adj[u]) {
                if (dist[v] < dist[u]) {
                    graph[u].push_back(v);
                }
            }
        }

        vector<int> dp(n + 1, -1);
        return dfs(1, n, dist, graph, dp);
    }
};
