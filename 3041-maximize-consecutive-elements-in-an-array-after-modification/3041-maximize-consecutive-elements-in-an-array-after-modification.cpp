class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int maxi = 1;
        for(int i = 0;i<n;i++){
            int num = nums[i];
            dp[num + 1] = dp[num] + 1;
            dp[num] = dp[num-1] + 1;
            maxi = max({maxi, dp[num], dp[num+1]});
        }
        return maxi;
    }
};