class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int maxEl = 0;
        int maxi = 0, maxj = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    int len = dp[i][j];
                    if (len > maxEl && (i - len) == (n - j)) {
                        maxEl = len;
                        maxi = i;
                        maxj = j;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        string res = "";
        int i = maxi, j = maxj;
        while (i > 0 && j > 0 && dp[i][j] > 0) {
            res += s1[i-1];
            i--; 
            j--;
        }
        return res;
    }
};
