class Solution {
public:
    bool isSafe(int node, vector<int>&color, vector<vector<int>>&adj){
        for(auto x : adj[node]){
            if(color[node] == color[x]) return false;
        }
        return true;
    }

    bool solve(int node, int n, vector<int>&color, vector<vector<int>>&adj){
        if(node == n) return true;

        for(int i=1; i<=4; i++){
            color[node] = i;
            if(isSafe(node, color, adj)) if(solve(node+1, n, color, adj)) return true;
            color[node] = -1;
        }
        return false;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto x : paths){
            int u = x[0]-1;
            int v = x[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, -1);
        solve(0, n, color, adj);
        return color;
    }
};