class Solution {
public:
    int dp[501];
    int solve(vector<int>&arr, int idx, int n, int k){
        if(idx >= n) return 0;
        int sum = 0;
        int maxSum = 0;
        if(dp[idx] != -1) return dp[idx];
        for (int i = idx; i < idx + k && i < n; i++) {
            int maxi = *max_element(arr.begin() + idx, arr.begin() + i + 1); 
            int cnt = i - idx + 1; 
            int curr = maxi * cnt + solve(arr, i + 1, n, k); 
            maxSum = max(maxSum, curr); 
        }
        return dp[idx] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, n, k);
    }
};