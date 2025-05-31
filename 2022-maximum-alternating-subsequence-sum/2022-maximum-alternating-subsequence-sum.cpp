class Solution {
public:
    int solve(vector<int>&nums, bool isEven, int idx){
        if(idx >= nums.size()) return 0;
        int take = solve(nums, !isEven, idx+1) + (isEven? nums[idx]: -nums[idx]);
        
        int skip = solve(nums, isEven, idx+1);
        return max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, true, 0);
    }
};