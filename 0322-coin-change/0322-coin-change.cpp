class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amt, int idx) {
        if (amt == 0) return 0;
        if (idx >= coins.size()) return INT_MAX - 1;

        if(dp[idx][amt] != -1) return dp[idx][amt]; 

        int take = INT_MAX;
        if (amt - coins[idx] >= 0) {
            int res = solve(coins, amt - coins[idx], idx);
            if (res != INT_MAX - 1) take = 1 + res;
        }

        int not_take = solve(coins, amt, idx + 1);

        return dp[idx][amt] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        int res = solve(coins, amount, 0);
        return (res == INT_MAX - 1) ? -1 : res;
    }
};
