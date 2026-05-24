class Solution {
public:
    int dp[1001];
    int solve(int i, vector<int>& arr, int d){
        int n = arr.size();
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j = i-1;j>=max(0, i-d);j--){
            if(arr[j] >= arr[i]) break;
            ans = max(ans, 1 + solve(j, arr, d));
        }
        for(int j = i+1;j<=min(n-1, i+d);j++){
            if(arr[j] >= arr[i]) break;
            ans = max(ans, 1 + solve(j, arr, d));
        }
        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 1;
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<n;i++){
            ans = max(ans, solve(i, arr, d));
        }
        return ans;
    }
};