class Solution {
public:
    void dfs(int curr, int anc, vector<vector<int>> &adj, vector<vector<int>>&res){
        for(int &ngbr: adj[curr]){
            if(res[ngbr].empty() || res[ngbr].back() != anc){
                res[ngbr].push_back(anc);
                dfs(ngbr, anc, adj, res);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<vector<int>> res(n);

        for(int i = 0;i<n;i++){
            dfs(i, i, adj, res);
        }
        return res;
    }
};