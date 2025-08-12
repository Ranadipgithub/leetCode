class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 1;
        int start = 0;
        
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                if (l == 1) {
                    dp[i][j] = 1;
                    maxLen = 1;
                    start = i;
                } else if (l == 2 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    maxLen = 2;
                    start = i;
                } else if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
