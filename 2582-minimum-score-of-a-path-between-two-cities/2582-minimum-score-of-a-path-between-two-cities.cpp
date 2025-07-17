class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& it : roads) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        queue<int> q;
        vector<int> visited(n + 1, 0);
        int mini = INT_MAX;
        q.push(1);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (visited[node]) continue;
            visited[node] = 1;
            for (auto& [v, w] : adj[node]) {
                mini = min(mini, w);
                if (!visited[v]) {
                    q.push(v);
                }
            }
        }
        return mini;
    }
};
