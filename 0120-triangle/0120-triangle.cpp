class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& triangle, int row, int idx, int n){
        if(row == n-1) return triangle[row][idx];
        if(dp[row][idx] != 1e5) return dp[row][idx];
        return dp[row][idx] = triangle[row][idx] + min(solve(triangle, row+1, idx, n), solve(triangle, row+1, idx+1, n));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.resize(n+1, vector<int>(n+1, 1e5));
        return solve(triangle, 0, 0, n);
    }
};