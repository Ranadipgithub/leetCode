class Solution {
public:
    int dp[2501][2501];

    int solve(vector<int>& nums, int i, int p) {
        int n = nums.size();
        if (i >= n) return 0;

        if (dp[i][p + 1] != -1) return dp[i][p + 1];

        int take = 0;
        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + solve(nums, i + 1, i);
        }
        int skip = solve(nums, i + 1, p);

        return dp[i][p + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        // memset(dp, -1, sizeof(dp)); 
        // return solve(nums, 0, -1);
        int n = nums.size();
        // vector<int> dp(n, 1);
        // int maxi = 1;
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<i;j++){
        //         if(nums[i] > nums[j]){
        //             dp[i] = max(dp[i], 1 + dp[j]);
        //             maxi = max(maxi, dp[i]);
        //         }
        //     }
        // }
        // return maxi;

        // using patience sorting
        vector<int> sorted;
        for(int i = 0;i<n;i++){
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]); // just greater than or equal to
            if(it == end(sorted)){
                sorted.push_back(nums[i]);
            } else{
                *it = nums[i];
            }
        }
        return sorted.size();
    }
};
