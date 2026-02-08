class Solution {
public:
    int dp[5005][305];
    int solve(int amount, int idx, vector<int>&coins){
        if(amount == 0) return 1;
        else if(idx >= coins.size()) return 0;
        if(dp[amount][idx] != -1) return dp[amount][idx];
        int take = 0;
        if(amount >= coins[idx]){
            take += solve(amount-coins[idx], idx, coins);
        }
        int skip = solve(amount, idx+1, coins);
        return dp[amount][idx] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        return solve(amount, 0, coins);
    }
};