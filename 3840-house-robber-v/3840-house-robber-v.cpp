class Solution {
public:
    long long dp[100005];
    long long solve(int idx, vector<int>& nums, vector<int>& colors){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long amt = 0;
        long long take = 0;
        if(idx < nums.size()-1 && colors[idx] != colors[idx+1]){
            take += nums[idx]+solve(idx+1, nums, colors);
        } else {
            take += nums[idx] + solve(idx+2, nums, colors);
        }
        long long skip = solve(idx+1, nums, colors);
        return dp[idx] = max(take, skip);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, colors);
    }
};