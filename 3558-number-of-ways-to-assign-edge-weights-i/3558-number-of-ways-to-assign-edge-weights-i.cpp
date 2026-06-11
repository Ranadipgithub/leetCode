class Solution {
public:
    int mod = 1e9 + 7;
    long long modpow(long long a, long long e = 1) {
        long long r = 1;
        while (e > 0) {
            if(e&1) r = (r*a)%mod;
            a = (a*a)%mod;
            e = e>>1;
        }
        return r;
    }
    int maxd = 0;
    void dfs(int node, int depth, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;
        maxd = max(maxd, depth);
        for (int v:adj[node]) {
            if (!visited[v]) {
                dfs(v, depth+1, visited, adj); 
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& it:edges) {
            int u =it[0]; 
            int v =it[1]; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n+1, 0);
        dfs(1, 0, visited, adj);
        if (maxd==0) return 0;
        // there should be odd no of 1's
        // let's say the depth is d
        // if d is odd then there can be 1 or 3 or ... or d 1's 
        // dc1 + dc3 + dc5  ... + dcd = 2^(d-1)
        // else if d is even then there can be 1 or 3 or ... or d-1 1's
        // dc1 + dc3 + dc5 + ... + dc(d-1) = 2^(d-1)
        return modpow(2, maxd - 1);
    }
};