class Solution {
public:
    unordered_map<int, int> dp[10001][11];
    int solve(int i, int j, int curr, vector<int>&nums, vector<int>&vals){
        if(i == nums.size()){
            if(j == vals.size()) return 0;
            return 1e9;
        }
        if(j == vals.size()) return 1e9;
        if(dp[i][j].count(curr)) return dp[i][j][curr];
        int ans = solve(i+1, j, curr&nums[i], nums, vals);
        if((curr & nums[i]) < vals[j]) return 1e9;
        if((curr & nums[i]) == vals[j]){
            ans = min(ans, nums[i] + solve(i+1, j+1, (1<<17) -1, nums, vals));
        }
        return dp[i][j][curr] = ans;
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int ans = solve(0, 0, (1 << 17) - 1, nums, andValues);
        return ans >= 1e9? -1: ans;
    }
};