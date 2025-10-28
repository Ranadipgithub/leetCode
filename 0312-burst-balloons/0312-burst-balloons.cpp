class Solution {
public:
    int dp[301][301];
    int solve(int i, int j, vector<int>&nums){
        int n = nums.size();
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int k = i;k<=j;k++){
            int left = i>0? nums[i-1]: 1;
            int right = j<n-1? nums[j+1]: 1;
            int score = left*right*nums[k] + solve(i, k-1, nums) + solve(k+1, j, nums);
            maxi = max(maxi, score);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, nums);
    }
};