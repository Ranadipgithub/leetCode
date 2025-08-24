class Solution {
public:
    vector<int> dp;
    int solve(vector<int>&nums, int idx){
        if(idx >= nums.size()-1){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int mini = 1e9;
        for(int i = 1; i <= nums[idx]; i++){
            if(idx + i < nums.size()) {
                mini = min(mini, 1 + solve(nums, idx + i));
            }
        }
        return dp[idx] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, -1);
        return solve(nums, 0);
    }
};