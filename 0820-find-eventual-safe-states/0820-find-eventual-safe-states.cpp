class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>&visited, vector<int>&inRecursion){
        visited[node] = 1;
        inRecursion[node] = 1;
        for(int &v: graph[node]){
            if(!visited[v] && dfs(graph, v, visited, inRecursion)){
                return true;
            } else if(inRecursion[v]){
                return true;
            }
        }
        inRecursion[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>inRecursion(n,0);
        vector<int>safe;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(graph, i, visited, inRecursion);
            }
        }
        for(int i = 0;i<n;i++){
            if(inRecursion[i] == false){
                safe.push_back(i);
            }
        }
        return safe;
    }
};