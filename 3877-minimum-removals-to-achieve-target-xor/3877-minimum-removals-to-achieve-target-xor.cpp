class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, vector<int>& nums, int xorr, int target){
        int n = nums.size();
        if(i == n){
            if(xorr == target) return 0;
            return 1e9;
        }
        if(dp[i][xorr] != -1) return dp[i][xorr];
        int take = 1 + solve(i+1, nums, xorr ^ nums[i], target);
        int skip = solve(i+1, nums, xorr, target);

        return dp[i][xorr] = min(take, skip);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int xorr = 0;
        for(int num : nums) xorr ^= num;
        dp.assign(n, vector<int>(17000, -1));
        int cnt = solve(0, nums, xorr, target);
        if(cnt == 1e9) return -1;
        return cnt;
    }
};