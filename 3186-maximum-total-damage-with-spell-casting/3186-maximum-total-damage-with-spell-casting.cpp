class Solution {
public:
    vector<long long> dp;
    long long solve(vector<int>& nums, unordered_map<int, long long>&mpp, int idx){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int next = upper_bound(nums.begin()+idx, nums.end(), nums[idx]+2) - nums.begin();
        long long take = mpp[nums[idx]] + solve(nums, mpp, next);
        long long skip = solve(nums, mpp, idx+1);
        return dp[idx] = max(take, skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        dp.assign(n, -1);
        unordered_map<int, long long> mpp;
        for(auto it: power) mpp[it] += it;
        vector<int> temp;
        for(auto it: mpp) temp.push_back(it.first);
        sort(temp.begin(), temp.end());
        return solve(temp, mpp, 0);
    }
};