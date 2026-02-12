class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i == n-1 && j == m-1) return 1;
        if(i >= n) return 0;
        if(j >= m) return 0;
        if(grid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = solve(i+1, j, n, m, grid);
        int op2 = solve(i, j+1, n, m , grid);

        return dp[i][j] = op1 + op2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[n-1][m-1] == 1) return 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, m, grid);
    }
};