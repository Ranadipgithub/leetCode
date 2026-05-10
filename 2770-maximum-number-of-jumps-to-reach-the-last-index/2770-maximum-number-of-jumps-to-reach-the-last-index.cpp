class Solution {
public:
    // int dp[1001];
    // int solve(int i, vector<vector<int>>&adj, int n){
    //     if(i == n-1) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int maxi = -1;
    //     for(int &v: adj[i]){
    //         int res = solve(v, adj, n);
    //         if(res != -1){
    //             maxi = max(maxi, 1 + res);
    //         }
    //     }
    //     return dp[i] = maxi;
    // }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(abs(nums[j]-nums[i]) <= target){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> dp(n, -1);
        dp[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            int maxi = -1;
            for(int &j: adj[i]){
                int res = dp[j];
                if(res != -1){
                    maxi = max(maxi, 1 + res);
                }
            }
            dp[i] = maxi;
        }
        return dp[0];
    }
};