class Solution {
public:
    int result = -1;
    void dfs(vector<int>& edges, int node, vector<bool>&visited, vector<bool>&inRecursion, vector<int>&count){
        if(node != -1){
            visited[node] = true;
            inRecursion[node] = true;

            int v = edges[node];
            if(v != -1 && !visited[v]){
                count[v] = count[node] + 1;
                dfs(edges, v, visited, inRecursion, count);
            } else if(v != -1 && inRecursion[v] == true){
                result = max(result, count[node]-count[v]+1);
            }
            inRecursion[node] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool>inRecursion(n, false);
        vector<int> count(n, 0);

        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(edges, i, visited, inRecursion, count);
            }
        }
        return result;
    }
};