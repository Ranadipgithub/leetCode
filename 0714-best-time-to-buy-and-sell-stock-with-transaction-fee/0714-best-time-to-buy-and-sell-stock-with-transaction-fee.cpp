class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&prices, int idx, int canBuy, int fee){
        if(idx >= prices.size()) return 0;
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        int profit = 0;
        if(canBuy){
            profit = max((-prices[idx] + solve(prices, idx+1, 0, fee)), (0 + solve(prices, idx+1, 1, fee)));
        } else{
            profit = max((prices[idx] + solve(prices, idx+1, 1, fee) - fee), (0+ solve(prices, idx+1, 0, fee)));
        }
        return dp[idx][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.resize(n+1, vector<int>(2, -1));
        return solve(prices, 0, 1, fee);
    }
};