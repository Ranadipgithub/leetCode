class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>> &grid, int i , int j, int n, int m){
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(i < 0 || i >=n|| j<0 || j>= m) return INT_MAX;
        int right = solve(grid, i, j+1, n, m);
        int bottom = solve(grid, i+1, j, n, m);
        return dp[i][j] = grid[i][j] + min(right, bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, n, m);
    }
};