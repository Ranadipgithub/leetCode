class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>&color, int currColor){
        color[node] = currColor;
        for(int &v: graph[node]){
            if(color[v] == color[node]){
                return false;
            }
            if(color[v] == -1){
                int colorV = 1 - color[node];
                if(dfs(graph, v, color, colorV) == false) return false;
            }
        }
        return true;
    }
    bool bfs(vector<vector<int>>& graph, int node, vector<int>&color, int currColor){
        queue<int> q;
        q.push(node);
        color[node] = currColor;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v: graph[u]){
                if(color[v] == color[u]){
                    return false;
                }
                if(color[v] == -1){
                    color[v] = 1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                if(!bfs(graph, i, color, 1)){
                    return false;
                }
            }
        }
        return true;
    }
};