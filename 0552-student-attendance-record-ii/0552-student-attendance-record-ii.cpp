class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[100005][3][4];

    int solve(int abs, int late, int n) {
        if (abs >= 2) return 0;
        if (late >= 3) return 0;
        if (n == 0) return 1;

        if (dp[n][abs][late] != -1) return dp[n][abs][late];

        long long res = 0;
        res = (res + solve(abs + 1, 0, n - 1)) % MOD;
        res = (res + solve(abs, late + 1, n - 1)) % MOD;
        res = (res + solve(abs, 0, n - 1)) % MOD; 

        return dp[n][abs][late] = res;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n);
    }
};