class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        totalSum = sum(nums)
        sum1 = 0
        for i in range(n):
            right = totalSum - sum1 - nums[i]
            if(sum1 == right):
                return i
            sum1 += nums[i]
        return -1