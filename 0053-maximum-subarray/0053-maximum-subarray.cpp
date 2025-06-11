class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1);
    }

    int divideAndConquer(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];

        int mid = left + (right - left) / 2;

        int leftMax = divideAndConquer(nums, left, mid);
        int rightMax = divideAndConquer(nums, mid + 1, right);
        int crossMax = maxCrossingSum(nums, left, mid, right);

        return max({leftMax, rightMax, crossMax});
    }

    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN, sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }
};
