class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> adj(n * m);
        vector<int> indegree(n * m, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(auto &dir: directions){
                    int newi = i + dir[0];
                    int newj = j + dir[1];
                    if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
                    if(matrix[newi][newj] <= matrix[i][j]) continue;
                    int u = newi * m + newj;
                    int v = i * m + j;
                    adj[u].push_back(v);
                    indegree[v]++;
                }
            }
        }

        queue<int> q;
        for(int i = 0; i < n * m; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int len = 0;
        while(!q.empty()){
            int sz = q.size();
            len++;
            while(sz--){
                int u = q.front();
                q.pop();

                for(int &v: adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 0) q.push(v);
                }
            }
        }
        return len;
    }
};