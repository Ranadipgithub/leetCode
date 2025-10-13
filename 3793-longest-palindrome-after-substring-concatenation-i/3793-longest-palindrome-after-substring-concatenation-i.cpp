class Solution {
public:
    bool isPal(const string& str) {
        string temp = str;
        reverse(temp.begin(), temp.end());
        return str == temp;
    }

    int longestPalindrome(string s, string t) {
        int n = s.size();
        int m = t.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub_s = s.substr(i, j - i + 1);
                if (isPal(sub_s)) {
                    maxLen = max(maxLen, (int)sub_s.length());
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                string sub_t = t.substr(i, j - i + 1);
                if (isPal(sub_t)) {
                    maxLen = max(maxLen, (int)sub_t.length());
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub_s = s.substr(i, j - i + 1);
                for (int k = 0; k < m; k++) {
                    for (int l = k; l < m; l++) {
                        string sub_t = t.substr(k, l - k + 1);
                        if (isPal(sub_s + sub_t)) {
                            maxLen = max(maxLen, (int)(sub_s.length() + sub_t.length()));
                        }
                    }
                }
            }
        }

        return maxLen;
    }
};