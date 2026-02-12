class Solution {
public:
    int dp[201][201];
    int solve(int i, int j, int n, int m, vector<vector<int>>&grid){
        if(i == n-1 && j == m-1) return grid[i][j];
        if(i >= n || j >= m) return 1e5;
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = grid[i][j] + solve(i+1, j, n, m, grid);
        int op2 = grid[i][j] + solve(i, j+1, n, m, grid);
        return dp[i][j] = min(op1, op2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, n, m, grid);
    }
};