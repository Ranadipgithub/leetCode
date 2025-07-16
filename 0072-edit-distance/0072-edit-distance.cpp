class Solution {
public:
    int t[501][501];

    int solve(string &word1, string &word2, int n, int m) {
        if(m == 0) return n;
        else if(n == 0) return m;
        if(t[n][m] != -1) return t[n][m];

        if(word1[n-1] == word2[m-1]) 
            return t[n][m] = solve(word1, word2, n-1, m-1);
        else {
            int insert = 1 + solve(word1, word2, n, m-1);
            int deleteOp = 1 + solve(word1, word2, n-1, m);
            int replace = 1 + solve(word1, word2, n-1, m-1);
            return t[n][m] = min({insert, deleteOp, replace});
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }

        return dp[n][m];
    }
};
