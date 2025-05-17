class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m) return false; 

        if(grid[i][j] != 0) return true;

        grid[i][j] = -1;

        bool up = dfs(grid, i-1, j);
        bool down = dfs(grid, i+1, j);
        bool left = dfs(grid, i, j-1);
        bool right = dfs(grid, i, j+1);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0){
                    if(dfs(grid, i, j)) cnt++;
                }
            }
        }
        return cnt;
    }
};