class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int>&visited, unordered_map<int, int> &ans){
        visited[node] = 1;
        ans[node] = 1;
        for(auto &v: adj[node]){
            if(!visited[v]){
                dfs(v, adj, visited, ans);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if (!visited[i]) {
                unordered_map<int, int> ans;
                dfs(i, adj, visited, ans);

                int prev = ans.size()-1; 
                bool sameDegree = true;

                for (auto it : ans) {
                    if (adj[it.first].size() != prev) {
                        sameDegree = false;
                        break;
                    }
                }

                if (sameDegree) cnt++;
            }

        }
        return cnt;
    }
};