class Solution {
public:
    int n, m;
    int dp[201][201];
    long long solve(int i, int j, vector<vector<int>> &grid){
        if(i >= n || j >= m || i < 0 || j < 0) return 1e9;
        if(i == n-1) return grid[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        long long minSum = 1e9;
        for(int k = 0;k<m;k++){
            if(k != j){
                long long sum = grid[i][j] + solve(i+1, k, grid);
                minSum = min(minSum, sum);
            }
        }
        return dp[i][j] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i = 0;i<201;i++){
            for(int j = 0;j<201;j++){
                dp[i][j] = INT_MAX;
            }
        }
        int mini = 1e9;
        for(int j = 0;j<m;j++){
            mini = min(mini, (int)solve(0, j, grid));
        }
        return mini;
    }
};