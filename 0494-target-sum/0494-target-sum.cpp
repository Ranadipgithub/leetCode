class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); 

        if ((sum - target) < 0 || (sum - target) % 2 != 0) {
            return 0;
        }

        int t = (sum - target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]; 
            }
        }

        return dp[n][t];
    }
};
