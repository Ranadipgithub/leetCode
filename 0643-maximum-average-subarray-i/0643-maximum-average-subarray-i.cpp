class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxSum = 0;

        for (int i = 0; i < k; i++) {
            maxSum += nums[i];
        }

        double currSum = maxSum;

        for (int i = k; i < n; i++) {
            currSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currSum);
        }

        return maxSum / k;
    }
};
