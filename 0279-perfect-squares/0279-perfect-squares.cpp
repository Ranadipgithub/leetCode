class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int mini = INT_MAX;

        for (int i = 1; i * i <= n; ++i) {
            mini = min(mini, solve(n - i * i) + 1);
        }

        return dp[n] = mini;
    }

    int numSquares(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};
