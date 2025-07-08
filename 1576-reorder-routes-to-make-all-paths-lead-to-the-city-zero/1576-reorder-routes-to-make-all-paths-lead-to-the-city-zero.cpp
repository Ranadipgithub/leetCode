class Solution {
public:
    void dfs(int node,
             const vector<vector<pair<int,int>>> &adj,
             vector<bool> &visited,
             int &cnt)
    {
        visited[node] = true;
        for (auto &p : adj[node]) {
            int nei  = p.first;
            int cost = p.second;
            if (!visited[nei]) {
                cnt += cost;           
                dfs(nei, adj, visited, cnt);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<bool> visited(n, false);
        int cnt = 0;
        dfs(0, adj, visited, cnt);
        return cnt;
    }
};
