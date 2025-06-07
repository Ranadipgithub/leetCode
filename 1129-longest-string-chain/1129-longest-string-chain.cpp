class Solution {
public:
    bool isSeq(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j]) i++;
            j++;
        }
        return i == n;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const string& a, const string& b) {
                 return a.size() < b.size();
             });

        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((words[i].size() == words[j].size() + 1) && isSeq(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
