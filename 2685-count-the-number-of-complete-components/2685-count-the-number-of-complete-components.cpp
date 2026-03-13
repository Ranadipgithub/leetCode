class Solution {
public:
    bool check(int node, unordered_map<int, vector<int>> &adj, vector<int>&visited, int cnt){
        visited[node] = 1;
        if(adj[node].size() != cnt-1) return false;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(!check(it, adj, visited, cnt)) return false;
            }
        }
        return true;
    }
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int>&visited, int &cnt){
        visited[node] = 1;
        cnt++;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited, cnt);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        unordered_map<int, int> mpp;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                int cnt = 0;
                dfs(i, adj, visited, cnt);
                mpp[i] = cnt;
            }
        }

        visited.assign(n, 0);
        int cnt = mpp.size();
        for(auto it: mpp){
            if(!check(it.first, adj, visited, it.second)) cnt--;
        }
        return cnt;
    }
};