class Solution {
public:
    int dfs(int node, vector<int>& visited, unordered_map<int, vector<int>>& adj) {
        visited[node] = 1;
        int nodes = 1; 
        for (auto& v : adj[node]) {
            if (!visited[v]) {
                nodes += dfs(v, visited, adj);
            }
        }
        return nodes;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        vector<int> componentSize;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int size = dfs(i, visited, adj);
                componentSize.push_back(size);
            }
        }

        long long sum = accumulate(componentSize.begin(), componentSize.end(), 0);
        long long prev = 0;
        long long ans = 0;

        for(int i = 0;i<componentSize.size();i++){
            prev += componentSize[i];
            ans += componentSize[i]*(sum-prev);
        }

        // long long ans = 0, sum = 0;
        // for (int sz : componentSize) {
        //     ans += 1LL * sz * (n - sz - sum);
        //     sum += sz;
        // }

        return ans;
    }
};
