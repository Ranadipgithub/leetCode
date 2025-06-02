class Solution {
public:
    // vector<vector<int>>dp;
    // int solve(vector<int>&coins, int amt, int n){
    //     if(amt == 0) return 0;
    //     if(n == 0 || amt < 0) return 1e9;
    //     if(dp[n][amt] != -1) return dp[n][amt];
    //     int take = 1e9;
    //     if(coins[n-1] <= amt){
    //         take = 1+solve(coins, amt-coins[n-1], n);
    //     }
    //     int skip = solve(coins, amt, n-1);
    //     return dp[n][amt] = min(take, skip);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp.assign(n+1, vector<int>(amount+1, -1));
        // int ans = solve(coins, amount, n);
        // return ans == 1e9? -1: ans;

        vector<vector<int>>dp(n+1, vector<int>(amount+1, 1e9));
        for(int i = 0;i<=n;i++) dp[i][0] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=amount;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount] == 1e9? -1: dp[n][amount];
    }
};