class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>&prices, int idx, int canBuy){
        if(idx >= prices.size()) return 0;
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        int profit = 0;
        if(canBuy){
            profit = max((-prices[idx] + solve(prices, idx+1, 0)), (0 + solve(prices, idx+1, 1)));
        } else{
            profit  = max((prices[idx] + solve(prices, idx+2, 1)), (0 + solve(prices, idx+1, 0)));
        }
        return dp[idx][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 1);
    }
};