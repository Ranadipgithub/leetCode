class Solution {
public:
    int mod = 1e9 + 7;
    long long modpow(long long a, long long b) {
        if(b == 0) return 1;
        long long half = modpow(a, b/2);
        long long res = (half * half)%mod;
        if(b%2 == 1) res = (res * a)%mod;
        return res;
    }
    int findLca(int u, int v, unordered_map<int, vector<int>> &adj, vector<int>&dist, vector<vector<int>>&up, int col){
        if(dist[u] < dist[v]) swap(u, v);
        int diff = dist[u] - dist[v];
        for(int j = col-1;j>=0;j--){
            if((diff & (1<<j))) u = up[u][j];
        }
        if(u == v) return u;
        for(int j = col-1;j>=0;j--){
            if(up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        int maxi = 1;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            maxi = max(maxi, u);
            maxi = max(maxi, v);
        }
        int col = log2(maxi)+1;
        vector<vector<int>> up(maxi+1, vector<int>(col, 0));
        vector<int> dist(maxi+1, 0);
        vector<int> visited(maxi+1, 0);
        visited[1] = 1;
        queue<int> q;
        q.push(1);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int u = q.front();
                q.pop();

                dist[u] = level;
                for(auto &v: adj[u]){
                    if(!visited[v]){
                        visited[v] = 1;
                        up[v][0] = u;
                        q.push(v);
                    }
                }
            }
            level++;
        }
        for(int j = 1;j<col;j++){
            for(int node = 1;node <= maxi;node++){
                up[node][j] = up[up[node][j-1]][j-1];
            }
        }
        vector<int> res;
        for(auto &it: queries){
            int u = it[0], v = it[1];
            int dist1 = dist[u];
            int dist2 = dist[v];
            int lca = findLca(u, v, adj, dist, up, col);
            int dist3 = dist[lca];
            int maxd = dist1 + dist2 - 2*dist3;
            if(maxd == 0){
                res.push_back(0);
                continue;
            }
            int ans = modpow(2, maxd - 1);
            res.push_back(ans);
        }
        return res;
    }
};