class Solution {
public:
    vector<vector<long long>>dp;
    long long solve(vector<int>&nums, bool isEven, long long idx){
        if(idx >= nums.size()) return 0;
        if(dp[idx][isEven] != -1) return dp[idx][isEven];
        long long take = solve(nums, !isEven, idx+1) + (isEven? nums[idx]: -nums[idx]);
        long long skip = solve(nums, isEven, idx+1);
        return dp[idx][isEven] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        // dp = vector<vector<long long>>(n, vector<long long>(2, -1));
        // return solve(nums, true, 0);
        vector<vector<long long>>t(n+1, vector<long long>(2, 0));
        for(int i = 1;i<n+1;i++){
            t[i][0] = max(t[i-1][1] - nums[i-1], t[i-1][0]);
            t[i][1] = max(t[i-1][0] + nums[i-1], t[i-1][1]);
        }
        return max(t[n][0], t[n][1]);
    }
};