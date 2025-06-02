class Solution {
public:
    vector<vector<int>> dp;
    int solve(const vector<int>& prices, int i, int lastIdx) {
        int n = prices.size();
        if (i > n) return 0;

        if (dp[i][lastIdx] != -1) 
            return dp[i][lastIdx];

        if (i > lastIdx) {
            int nextLast = min(n, 2 * i);
            return dp[i][lastIdx] = prices[i - 1] + solve(prices, i + 1, nextLast);
        }
        int takeFree = solve(prices, i + 1, lastIdx);
        int extended = min(n, 2*i);
        int buyAnyway = prices[i - 1] + solve(prices, i + 1, extended);
        return dp[i][lastIdx] = min(takeFree, buyAnyway);
    }

    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(prices, 1, 0);
    }
};
