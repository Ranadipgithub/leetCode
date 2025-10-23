class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n, int m){
        if (n == 0) return 0;           
        if (n < 0 || m == 0) return 1e9;

        if(dp[n][m] != -1) return dp[n][m];

        int take = 1e9;
        if (m * m <= n)  
            take = 1 + solve(n - m * m, m);

        int not_take = solve(n, m - 1);

        return dp[n][m] = min(take, not_take);
    }

    int numSquares(int n) {
        int m = sqrt(n);
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(n, m);
    }
};