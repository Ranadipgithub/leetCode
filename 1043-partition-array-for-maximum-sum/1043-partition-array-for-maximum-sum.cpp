class Solution {
public:
    int dp[501];
    int solve(int i, vector<int>& arr, int k){
        int n = arr.size();
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = 0, currMax = 0;
        for(int len = 1; len <= k && i + len - 1 < n; len++){
            currMax = max(currMax, arr[i+len-1]);
            ans = max(ans, currMax * len + solve(i + len, arr, k));
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, arr, k);
    }
};