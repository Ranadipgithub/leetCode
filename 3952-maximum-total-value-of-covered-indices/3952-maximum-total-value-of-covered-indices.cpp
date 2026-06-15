class Solution {
public:
    long long dp[100001][2];
    long long solve(int idx, string &s, vector<int>&nums, int taken){
        if(idx == nums.size()) return 0;
        // at every index you have to options either to take it or skip it
        // you can only take if s[i] == '1' || s[i+1] == '1'
        // we also have to maintain a taken state to check whether the el at
        // current idx is already taken by prev el or not 
        if(dp[idx][taken] != -1) return dp[idx][taken];
        long long ans = solve(idx+1, s, nums, 0);
        if(s[idx] == '1' && !taken){
            ans = max(ans, nums[idx] + solve(idx+1, s, nums, 0));
        } 
        if(idx+1 < nums.size() && s[idx+1] == '1'){
            ans = max(ans, nums[idx] + solve(idx+1, s, nums, 1));
        }
        return dp[idx][taken] = ans;
    }
    long long maxTotal(vector<int>& nums, string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s, nums, 0);
    }
};