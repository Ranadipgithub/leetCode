class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 1;

        vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int modSum = (nums[i] + nums[j]) % k;
                int prevLen = dp[j].count(modSum) ? dp[j][modSum] : 1; 
                dp[i][modSum] = max(dp[i][modSum], prevLen + 1);
                maxLen = max(maxLen, dp[i][modSum]);
            }
        }

        return maxLen;
    }
};
