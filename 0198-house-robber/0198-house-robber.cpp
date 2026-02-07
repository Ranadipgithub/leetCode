class Solution {
public:
    int dp[105];
    int solve(vector<int>&nums, int idx){
        int n = nums.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = 0;
        if(idx < n)
            take += nums[idx] + solve(nums, idx+2);
        int skip = solve(nums, idx+1);
        return dp[idx] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};