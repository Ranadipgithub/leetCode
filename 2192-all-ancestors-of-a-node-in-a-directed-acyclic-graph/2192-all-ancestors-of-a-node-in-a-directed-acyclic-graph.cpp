class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int>&res, vector<int>&visited){
        visited[node] = 1;
        for(int &v: adj[node]){
            if(!visited[v]){
                res.push_back(v);
                dfs(v, adj, res, visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        vector<vector<int>> res(n);
        for(int i = 0;i<n;i++){
            vector<int> visited(n, 0);
            dfs(i, adj, res[i], visited);
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};