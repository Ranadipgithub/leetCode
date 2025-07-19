class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int idx, int canBuy, int cnt) {
        if(idx == prices.size() || cnt >= 4){
            return 0;
        }
        if(dp[idx][canBuy][cnt] != -1) return dp[idx][canBuy][cnt];
        
        int profit = 0;
        if(canBuy){
            profit = max(-prices[idx] + solve(prices, idx+1, 0, cnt+1),
                         solve(prices, idx+1, 1, cnt));
        } else {
            profit = max(prices[idx] + solve(prices, idx+1, 1, cnt+1),
                         solve(prices, idx+1, 0, cnt));
        }
        return dp[idx][canBuy][cnt] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1, vector<vector<int>>(2, vector<int>(5, -1)));
        return solve(prices, 0, 1, 0); 
    }
};
