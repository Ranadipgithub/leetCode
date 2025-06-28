class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long sum = 0, maxSum = 0;
        unordered_map<int, int> mpp;

        while (j < n) {
            sum += nums[j];
            mpp[nums[j]]++;

            if (j - i + 1 > k) {
                sum -= nums[i];
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }

            if (j - i + 1 == k) {
                if (mpp.size() == k) {
                    maxSum = max(maxSum, sum);
                }
            }

            j++;
        }

        return maxSum;
    }
};
