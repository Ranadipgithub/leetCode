class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int maxi = prices[n-1];
        for(int i = n-2;i>=0;i--){
            int profit = maxi - prices[i];
            maxProfit = max(maxProfit, profit);
            maxi = max(maxi, prices[i]);
        }
        return maxProfit;
    }
};