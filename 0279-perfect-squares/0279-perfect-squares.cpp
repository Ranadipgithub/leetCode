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
        // memset(dp, -1, sizeof(dp));
        // return solve(n);

        if(n <= 3) return n;

        vector<int> t(n+1);
        t[1] = 1, t[2] = 2, t[3] = 3;
        for(int i = 4;i<=n;i++){
            int mini = INT_MAX;
            for(int j = sqrt(i);j>=1;j--){
                mini = min(mini, 1 + t[i-j*j]);
            }
            t[i] = mini;
        }
        return t[n];
    }
};