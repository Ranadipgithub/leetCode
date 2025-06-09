class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        for(int l = 1;l<=n;l++){
            for(int i = 0;i+l-1<n;i++){
                int j = i+l-1;
                if(i == j) t[i][j] = true;
                else if(i+1 == j) t[i][j] = s[i] == s[j];
                else t[i][j] = s[i] == s[j] && t[i+1][j-1];
            }
        }

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<n;i++){
            if(t[0][i]) dp[i] = 0; // no cuts required
            else{
                for(int k = 0;k<i;k++){
                    if(t[k+1][i] && 1 + dp[k] < dp[i]){
                        dp[i] = 1+dp[k];
                    }
                }
            }
        }
        return dp[n-1];
    }
};