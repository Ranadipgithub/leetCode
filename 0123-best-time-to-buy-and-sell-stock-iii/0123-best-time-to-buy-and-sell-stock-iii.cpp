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
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0, prices);
    }
};