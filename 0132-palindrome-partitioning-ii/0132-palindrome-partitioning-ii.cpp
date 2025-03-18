class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    pal[i][j] = (L == 2) ? true : pal[i+1][j-1];
                } else {
                    pal[i][j] = false;
                }
            }
        }
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = -1; 
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (pal[j][i - 1]) { 
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};
