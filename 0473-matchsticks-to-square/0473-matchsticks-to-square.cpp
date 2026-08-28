class Solution {
public:
    vector<int> dp;
    bool solve(int mask, int curr, int target, vector<int>&nums){
        int n = nums.size();
        if(mask == (1 << n) - 1) return true;
        if(dp[mask] != -1) return dp[mask];
        for(int i = 0;i<n;i++){
            if((mask & (1 << i)) == 0){
                if(curr + nums[i] <= target){
                    int new_sum = (curr+nums[i])%target;
                    if(solve((mask | (1<<i)), new_sum, target, nums)) return  dp[mask] = true;
                }
            }
        }
        return dp[mask] =  false;
    }
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%4) return false;
        int target = sum/4;
        sort(nums.rbegin(), nums.rend());
        if(nums[0] > target) return false;
        dp.assign((1<<n), -1);
        return solve(0, 0, target, nums);
    }
};