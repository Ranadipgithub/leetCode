class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int>&visited){
        visited[node] = 1;
        for(auto &v: adj[node]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int>> adj;
        for(int u = 0;u<rooms.size();u++){
            for(int v = 0;v<rooms[u].size();v++){
                adj[u].push_back(rooms[u][v]);
            }
        }
        vector<int> visited(rooms.size(), 0);
        dfs(0, adj, visited);
        for(int i = 0;i<rooms.size();i++){
            if(visited[i] == 0) return false;
        }
        return true;
    }
};