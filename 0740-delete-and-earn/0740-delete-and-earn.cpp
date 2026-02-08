class Solution {
public:
    int dp[20001];
    int solve(vector<int>&temp, int idx){
        int n = temp.size();
        if(dp[idx] != -1) return dp[idx];
        if(idx >= n) return 0;
        int take = 0;
        if(idx < n) take = temp[idx] + solve(temp, idx+2);
        int skip = solve(temp, idx+1);
        return dp[idx] = max(take, skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        unordered_map<int, int> mpp;
        for(auto it: nums) mpp[it] += it;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> temp(maxi+1);
        for(int i = 0;i<temp.size();i++){
            temp[i] = mpp[i];
            cout << temp[i] << " ";
        }
        return solve(temp, 0);
    }
};