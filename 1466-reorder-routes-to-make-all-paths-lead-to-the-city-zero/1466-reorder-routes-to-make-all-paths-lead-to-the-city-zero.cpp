class Solution {
public:
    void dfs(int node, unordered_map<int, vector<pair<int, int>>> &adj, vector<int>&visited, int &cnt){
        for(auto it: adj[node]){
            int v = it.first, dir = it.second;
            if(!visited[v]){
                visited[v] = 1;
                if(dir == 0) cnt++;
                dfs(v, adj, visited, cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &edge: connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        int cnt = 0;
        vector<int> visited(n, 0);
        visited[0] = 1;
        dfs(0, adj, visited, cnt);
        return cnt;
    }
};