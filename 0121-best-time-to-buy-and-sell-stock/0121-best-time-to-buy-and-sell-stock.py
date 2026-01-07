class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxi = 0
        ans = 0
        for x in reversed(prices):
            maxi = max(maxi, x)
            ans = max(ans, maxi - x)
            
        return ans