class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int idx = n-1;idx>=0;idx--){
            for(int canBuy = 0;canBuy <= 1;canBuy++){
                for(int cnt = 0;cnt < k;cnt++){
                    int profit = 0;
                    if(canBuy){
                        profit += max((-prices[idx] + dp[idx+1][0][cnt]), dp[idx+1][1][cnt]);
                    } else {
                        profit += max((prices[idx] + dp[idx+1][1][cnt+1]), dp[idx+1][0][cnt]);
                    }
                    dp[idx][canBuy][cnt] = profit;
                }
            }
        }
        return dp[0][1][0];
    }
};