class Solution {
    public int solve(int[] prices, int idx, int canBuy, Integer[][] dp) {
        int n = prices.length;
        if (idx >= n) return 0;

        if (dp[idx][canBuy] != null) return dp[idx][canBuy];

        int profit = 0;
        if (canBuy == 1) {
            profit = Math.max(
                -prices[idx] + solve(prices, idx + 1, 0, dp),
                solve(prices, idx + 1, 1, dp)
            );
        } else {
            profit = Math.max(
                prices[idx] + solve(prices, idx + 1, 1, dp),
                solve(prices, idx + 1, 0, dp)
            );
        }
        return dp[idx][canBuy] = profit;
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        Integer[][] dp = new Integer[n][2]; 
        return solve(prices, 0, 1, dp);
    }
}
