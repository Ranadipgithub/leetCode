class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    long long dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        
        long long sum = grid[i][j]; 
        grid[i][j] = 0;

        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];
            if(newi < 0 || newi >= n || newj < 0 || newj >= m || grid[newi][newj] == 0) continue;

            sum += dfs(grid, newi, newj);
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    long long sum = dfs(grid, i, j); 
                    if(sum % k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};