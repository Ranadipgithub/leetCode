class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int n, m;
    bool dfs(int i, int j, char ch, vector<vector<char>>& grid, int pi, int pj){
        visited[i][j] = 1;
        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];
            if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
            if(grid[newi][newj] != ch) continue;
            if(newi == pi && newj == pj) continue;
            if(visited[newi][newj]) return true;
            if(dfs(newi, newj, ch, grid, i, j)) return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        visited.resize(n, vector<int>(m, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j]){
                    if(dfs(i, j, grid[i][j], grid, -1, -1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};