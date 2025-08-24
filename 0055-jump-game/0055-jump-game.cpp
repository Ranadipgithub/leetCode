class Solution {
public:
    vector<int> dp;
    bool solve(vector<int>& nums, int idx){
        if(idx >= nums.size() - 1) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i = 1; i <= nums[idx]; i++){
            if(solve(nums, idx + i)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, -1);
        return solve(nums, 0);
    }
};