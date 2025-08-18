class Solution {
    public int solve(int[] prices, int idx, int canBuy, int cnt, Integer[][][] dp){
        if(cnt >= 4 || idx >= prices.length) return 0;
        if(dp[idx][canBuy][cnt] != null) return dp[idx][canBuy][cnt];
        int profit = 0;
        if(canBuy == 1){
            profit = Math.max(-prices[idx] + solve(prices, idx+1, 0, cnt+1, dp), solve(prices, idx+1, 1, cnt, dp));
        } else{
            profit = Math.max(prices[idx] + solve(prices, idx+1, 1, cnt+1, dp), solve(prices, idx+1, 0, cnt, dp));
        }
        return dp[idx][canBuy][cnt] = profit;
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        Integer[][][] dp = new Integer[n][2][5];
        return solve(prices, 0, 1, 0, dp);
    }
}