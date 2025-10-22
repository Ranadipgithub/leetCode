class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = s1[i-1] + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        int total1 = 0;
        for(char c: s1){
            total1 += c;
        }
        int total2 = 0;
        for(char c: s2){
            total2 += c;
        }

        return (total1-dp[n][m]) + (total2-dp[n][m]);
    }
};