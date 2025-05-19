class Solution {
public:
    // void dfs(unordered_map<int, vector<int>> adj, int node, int ancestor, vector<vector<int>>&res){
    //     for(int &v: adj[node]){
    //         if(res[v].empty() || res[v].back() != ancestor){
    //             res[v].push_back(ancestor);
    //             dfs(adj, v, ancestor, res);
    //         }
    //     }
    // }
    void dfs(unordered_map<int, vector<int>> &adj, int node, vector<int>&visited){
        visited[node] = 1;
        for(int &v: adj[node]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<vector<int>>res;

        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        for(int u = 0;u<n;u++){
            vector<int> ancestor;
            vector<int> visited(n,0);
            dfs(adj, u, visited);

            for(int i = 0;i<n;i++){
                if(i == u) continue;
                if(visited[i] == 1){
                    ancestor.push_back(i);
                }
            }
            res.push_back(ancestor);
        }
        return res;
    }
};