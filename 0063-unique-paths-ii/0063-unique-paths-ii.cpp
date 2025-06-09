class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>&grid, int i , int j, int n, int m){
        if(i == n-1 && j == m-1) return 1;
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(grid, i, j+1, n, m);
        int left = solve(grid, i+1, j, n, m);
        return dp[i][j] = right + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        if(obstacleGrid[n-1][m-1] == 1) return 0;
        return solve(obstacleGrid, 0, 0, n, m);
    }
};