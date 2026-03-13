class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int>&visited){
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                dfs(it, adj, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int>> adj;
        int n = rooms.size();
        for(int i = 0;i<n;i++){
            adj[i] = rooms[i];
        }

        vector<int> visited(n, 0);
        visited[0] = 1;
        dfs(0, adj, visited);
        for(auto it: visited){
            if(it == 0) return false;
        }
        return true;
    }
};