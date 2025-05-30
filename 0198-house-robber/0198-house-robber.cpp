class Solution {
public:
    int dp[101];
    int solve(vector<int>&nums, int idx){
        int n = nums.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int steal = nums[idx] + solve(nums, idx+2);
        int skip = solve(nums, idx+1);
        return dp[idx] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));
        // return solve(nums, 0);
        vector<int>t(n+1, 0);
        t[0] = 0;
        t[1] = nums[0];
        for(int i = 2;i<=n;i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];
            t[i] = max(steal, skip);
        }
        return t[n];
    }
};