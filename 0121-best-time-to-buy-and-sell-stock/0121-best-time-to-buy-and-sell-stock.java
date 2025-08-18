class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int maxProfit = 0;
        int maxi = prices[n-1];
        for(int i = n-2;i>=0;i--){
            int profit = maxi - prices[i];
            maxProfit = Math.max(maxProfit, profit);
            maxi = Math.max(maxi, prices[i]);
        }
        return maxProfit;
    }
}