class Solution {
public:
    // int dp[101][101];
    // int solve(vector<vector<int>>&grid, int i , int j, int n, int m){
    //     if(i == n-1 && j == m-1) return 1;
    //     if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int right = solve(grid, i, j+1, n, m);
    //     int left = solve(grid, i+1, j, n, m);
    //     return dp[i][j] = right + left;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // First column
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }

        // First row
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[0][j] == 1) break;
            dp[0][j] = 1;
        }

        // Fill rest of the grid
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];
    }
};