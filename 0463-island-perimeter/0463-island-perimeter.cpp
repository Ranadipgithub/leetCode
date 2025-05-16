class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &peri){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n|| j<0 || j>=m || grid[i][j] == 0){
            peri++;
            return;
        }
        if(grid[i][j] == -1){
            return;
        }
        grid[i][j] = -1;
        dfs(grid, i+1, j, peri);
        dfs(grid, i-1, j, peri);
        dfs(grid, i, j+1, peri);
        dfs(grid, i, j-1, peri);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int peri = 0;
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         if(grid[i][j] == 1){
        //             dfs(grid, i, j, peri);
        //             return peri;
        //         }
        //     }
        // }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0) continue;
                if(i - 1 < 0 || grid[i - 1][j] == 0)
                peri++;

            // Check down
            if(i + 1 >= n || grid[i + 1][j] == 0)
                peri++;

            // Check left
            if(j - 1 < 0 || grid[i][j - 1] == 0)
                peri++;

            // Check right
            if(j + 1 >= m || grid[i][j + 1] == 0)
                peri++;
            }
        }
        return peri;
    }
};