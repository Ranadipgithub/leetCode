class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&prices, int index, int canBuy){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][canBuy] != -1) return dp[index][canBuy];
        int profit = 0;
        if(canBuy == 1){
            profit = max((-prices[index] + solve(prices, index+1, 0)), 0 + solve(prices, index+1, 1));
        } else{
            profit = max((prices[index] + solve(prices, index+1, 1)), 0 + solve(prices, index+1, 0));
        }
        return dp[index][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        return solve(prices, 0, 1);
    }
};