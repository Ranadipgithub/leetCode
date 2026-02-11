class Solution {
public:
    int dp[100001][2][3];
    int solve(int idx, int canBuy, int cnt, vector<int>&prices){
        if(cnt >= 2 || idx >= prices.size()) return 0;
        if(dp[idx][canBuy][cnt] != -1) return dp[idx][canBuy][cnt];
        int profit = 0;
        if(canBuy){
            profit += max((-prices[idx] + solve(idx+1, 0, cnt, prices)), solve(idx+1, 1, cnt, prices));
        } else {
            profit += max((prices[idx] + solve(idx+1, 1, cnt+1, prices)), solve(idx+1, 0, cnt, prices));
        }
        return dp[idx][canBuy][cnt] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // memset(dp, -1, sizeof(dp));

        // return solve(0, 1, 0, prices);

        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int idx = n-1;idx>=0;idx--){
            for(int canBuy = 0;canBuy <= 1;canBuy++){
                for(int cnt = 0;cnt < 2;cnt++){
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