class Solution {
public:
    int dp[10001];
    int solve(int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int mini = INT_MAX;
        for(int i = sqrt(n);i>=1;i--){
            mini = min(mini, 1 + solve(n - i*i));
        }
        return dp[n] = mini;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};