class Solution {
public:
    int dp[10001][15];
    int solve(vector<int>&coins, int amount, int idx){
        if(amount == 0) return 0;
        if(idx >= coins.size()) return 1e9;
        if(dp[amount][idx] != -1) return dp[amount][idx];
        int take = 1e9;
        if(amount >= coins[idx]){
            take = 1 + solve(coins, amount-coins[idx], idx);
        }
        int skip = solve(coins, amount, idx + 1);
        return dp[amount][idx] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount, 0);
        return ans == 1e9? -1: ans;
    }
};