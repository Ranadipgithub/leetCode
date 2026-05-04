class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int>&disc, vector<int>&low, vector<bool>&visited, vector<vector<int>> &res, int &cnt){
        disc[node] = low[node] = cnt;
        visited[node] = true;
        for(int &ngbr: adj[node]){
            if(ngbr == parent) continue;
            else if(visited[ngbr]){
                low[node] = min(low[node], low[ngbr]);
            } else {
                cnt++;
                dfs(ngbr, node, adj, disc, low, visited, res, cnt);
                if(low[ngbr] > disc[node]){
                    res.push_back({ngbr, node});
                }
                low[node] = min(low[node], low[ngbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &edge: connections){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> res;
        vector<int> disc(n); // discovery time
        vector<int> low(n); // low time
        vector<bool> visited(n, 0);
        int cnt = 0;
        dfs(0, -1, adj, disc, low, visited, res, cnt);
        return res;
    }
};