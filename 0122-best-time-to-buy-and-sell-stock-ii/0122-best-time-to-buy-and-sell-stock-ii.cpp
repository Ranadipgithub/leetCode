class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(vector<int>&prices, int idx, int canBuy){
    //     if(idx == prices.size()){
    //         return 0;
    //     }
    //     if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
    //     int profit = 0;
    //     if(canBuy == 1){
    //         profit = max((-prices[idx] + solve(prices, idx+1, 0)), 0 + solve(prices, idx+1, 1));
    //     } else{
    //         profit = max((prices[idx] + solve(prices, idx+1, 1)), 0 + solve(prices, idx+1, 0));
    //     }
    //     return dp[idx][canBuy] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp.resize(n, vector<int>(2, -1));

        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        dp[n][1] = dp[n][0] = 0;
        for(int idx = n-1;idx>=0;idx--){
            for(int canBuy = 0;canBuy<=1;canBuy++){
                int profit = 0;
                if(canBuy == 1){
                    profit = max((-prices[idx] + dp[idx+1][0]), 0 + dp[idx+1][1]);
                } else{
                    profit = max((prices[idx] + dp[idx+1][1]), 0 + dp[idx+1][0]);
                }
                dp[idx][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
};