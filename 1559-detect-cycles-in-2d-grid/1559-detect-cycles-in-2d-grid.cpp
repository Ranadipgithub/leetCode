class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int n, m;
    bool dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &visited, int pi, int pj){
        char ch = grid[i][j];
        visited[i][j] = true;
        for(auto &dir: directions){
            int newi = i + dir[0], newj = j + dir[1];
            if(newi < 0 || newi >= n || newj < 0 || newj >= m ) continue;
            if(grid[newi][newj] != ch) continue;
            if(newi == pi && newj == pj) continue;
            if(visited[newi][newj]) return true;
            if(dfs(newi, newj, grid, visited, i, j)) return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        // if a cell is already visited but it is not the parent that means there is a cycle
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j]){
                    if(dfs(i, j, grid, visited, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};