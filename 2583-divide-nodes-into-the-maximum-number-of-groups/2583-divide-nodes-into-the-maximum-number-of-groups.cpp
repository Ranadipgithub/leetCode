class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>> &adj, int node, vector<int>&colors, int currColor){
        colors[node] = currColor;
        for(auto &v: adj[node]){
            if(colors[v] == colors[node]) return false;
            if(colors[v] == -1){
                if(!isBipartite(adj, v, colors, 1-currColor)) return false;
            }
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int node, int n){
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();

                for(int &v: adj[curr]){ 
                    if(visited[v]) continue;
                    visited[v] = 1;
                    q.push(v);
                }
            }
            level++;
        }
        return level-1;
    }

    int getMaxGrp(unordered_map<int, vector<int>> &adj, int node, vector<int>&visited, vector<int>&levels){
        int maxGrp = levels[node];
        visited[node] = 1;
        for(int &v: adj[node]){
            if(!visited[v]) {
                maxGrp = max(maxGrp, getMaxGrp(adj, v, visited, levels));
            }
        }
        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1; // -1 to convert to 0-based indexing

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, -1);
        for(int i = 0; i < n; i++){
            if(colors[i] == -1){
                if(!isBipartite(adj, i, colors, 1)){
                    return -1;
                }
            }
        }

        vector<int> levels(n, 0);
        for(int i = 0; i < n; i++){
            levels[i] = bfs(adj, i, n);
        }

        int maxGrpEachComp = 0;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                maxGrpEachComp += getMaxGrp(adj, i, visited, levels);
            }
        }
        return maxGrpEachComp;
    }
};
