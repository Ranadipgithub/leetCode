class Solution {
public:
    // int dp[2001][2001];
    // bool solve(string &s1, string &s2, int m, int n) {
    //     // Base case: both strings are empty
    //     if (m == 0 && n == 0) return true;

    //     // If s1 is empty, s2 must be all '*'
    //     if (m == 0) {
    //         for (int i = 0; i < n; i++) {
    //             if (s2[i] != '*') return false;
    //         }
    //         return true;
    //     }

    //     // If s2 is empty and s1 is not, no match
    //     if (n == 0) return false;

    //     if(dp[m][n] != -1) return dp[m][n];

    //     // Characters match or pattern has '?'
    //     if (s1[m - 1] == s2[n - 1] || s2[n - 1] == '?') {
    //         return dp[m][n] = solve(s1, s2, m - 1, n - 1);
    //     }

    //     // If pattern has '*', it can match:
    //     // 1. zero characters (move pattern pointer)
    //     // 2. one or more characters (move string pointer)
    //     if (s2[n - 1] == '*') {
    //         return dp[m][n] = solve(s1, s2, m, n - 1) || solve(s1, s2, m - 1, n);
    //     }

    //     // If characters don't match and no wildcard
    //     return false;
    // }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; 

        // when s is empty
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};