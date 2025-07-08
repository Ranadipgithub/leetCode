class Solution {
public:
    void bfs(vector<vector<int>>& grid, int i, int j, int &area){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n||j<0 || j>=m || grid[i][j] != 1){
            return;
        }
        area += 1;
        grid[i][j] = -1;
        bfs(grid, i+1, j, area);
        bfs(grid, i-1, j, area);
        bfs(grid, i, j+1, area);
        bfs(grid, i, j-1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0, maxarea = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    bfs(grid, i, j, area);
                    maxarea = max(area, maxarea);
                }
            }
        }
        return maxarea;
    }
};