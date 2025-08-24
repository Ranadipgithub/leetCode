class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& visited, int parent, vector<int>& count){
        visited[node] = 1;
        for(int &v: graph[node]){
            if(v == parent) continue;  

            if(!visited[v]){
                count[v] = count[node] + 1; 
                if(!dfs(graph, v, visited, node, count)) return false;
            } else {
                int len = count[node] - count[v] + 1;
                if(len % 2 == 1) return false;  
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> count(n, 0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count[i] = 0; 
                if(!dfs(graph, i, visited, -1, count)) return false;
            }
        }
        return true;
    }
};