class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&coins, int amt, int n){
        if(n == 0){
            if(amt == 0) return 1;
            return 0;
        }
        if(dp[n][amt] != -1) return dp[n][amt];
        if(coins[n-1] <= amt){
            return dp[n][amt] = solve(coins, amt-coins[n-1], n) + solve(coins, amt, n-1);
        } else{
            return dp[n][amt] = solve(coins, amt, n-1);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n+1, vector<int>(amount+1, -1));
        return solve(coins, amount, n);
    }
};