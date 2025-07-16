class Solution {
public:
    int dp[2001][2001];
    bool solve(string &s1, string &s2, int m, int n) {
        // Base case: both strings are empty
        if (m == 0 && n == 0) return true;

        // If s1 is empty, s2 must be all '*'
        if (m == 0) {
            for (int i = 0; i < n; i++) {
                if (s2[i] != '*') return false;
            }
            return true;
        }

        // If s2 is empty and s1 is not, no match
        if (n == 0) return false;

        if(dp[m][n] != -1) return dp[m][n];

        // Characters match or pattern has '?'
        if (s1[m - 1] == s2[n - 1] || s2[n - 1] == '?') {
            return dp[m][n] = solve(s1, s2, m - 1, n - 1);
        }

        // If pattern has '*', it can match:
        // 1. zero characters (move pattern pointer)
        // 2. one or more characters (move string pointer)
        if (s2[n - 1] == '*') {
            return dp[m][n] = solve(s1, s2, m, n - 1) || solve(s1, s2, m - 1, n);
        }

        // If characters don't match and no wildcard
        return false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, p, m, n);
    }
};
