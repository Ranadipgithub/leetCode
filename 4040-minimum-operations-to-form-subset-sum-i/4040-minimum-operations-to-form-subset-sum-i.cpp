class Solution {
public:
    int dp[101][5001];
    int solve(int idx, vector<int>&nums, int sum){
        if(sum == 0) return 0;
        if(sum < 0) return 1e9;
        if(idx == nums.size()) return 1e9;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int skip = solve(idx+1, nums, sum);
        int take = solve(idx+1, nums, sum - nums[idx]);
        int ops = 1;
        for(int val = 2*nums[idx]; sum - val >= 0; val*=2){
            take = min(take, ops + solve(idx+1, nums, sum - val));
            ops++;
        }
        ops = 1;
        for(int val = nums[idx]/2; ; val/=2){
            take = min(take, ops + solve(idx+1, nums, sum - val));
            if(val == 0) break;
            ops++;
        }
        return dp[idx][sum] = min(take, skip);
    }
    int minOperations(vector<int>& nums, int sum) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, nums, sum);
        return ans == 1e9? -1: ans;
    }
};