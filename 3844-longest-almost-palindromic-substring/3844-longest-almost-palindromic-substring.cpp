class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s, int i, int j){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(dp[i][j] > 5) return INT_MAX;
        int ans = INT_MAX;
        if(s[i] == s[j]){
            ans = min(ans, solve(s, i+1, j-1));
        } else {
            ans = min(ans, 1 + min(solve(s, i+1, j), solve(s, i, j-1)));
        }
        return dp[i][j] = ans;
    }
    int almostPalindromic(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, 0));
        int ans = 1;
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                if(i == j) dp[i][j] = 0;
                else if(i+1 == j) dp[i][j] = (s[i] == s[j])? 0: 1;
                else {
                    if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                    else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
                if(dp[i][j] <= 1) ans = max(ans, j-i+1);
            }
        }
        return ans;
        // for(int i = 0;i<n;i++){
        //     for(int j = i;j<n;j++){
        //         if(j-i+1 <= ans) continue;
        //         int res = solve(s, i, j);
        //         if(res == 1 || res == 0){
        //             ans = max(ans, j-i+1);
        //         }
        //     }
        // }
        // return ans;
    }
};