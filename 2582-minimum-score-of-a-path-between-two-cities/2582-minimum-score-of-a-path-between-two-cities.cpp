class Solution {
public:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>> &adj, vector<int>& visited, int &mini) {
        visited[node] = 1;
        for (auto [v, w] : adj[node]) {
            mini = min(mini, w); 
            if (!visited[v]) {
                dfs(v, adj, visited, mini);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &it : roads) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> visited(n+1, 0);
        int mini = INT_MAX;
        dfs(1, adj, visited, mini); 
        return mini;
    }
};
