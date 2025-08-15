class Solution {
public:
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0; 
        lps[0] = 0; 
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));
        string temp = s + "-" + rev;
        vector<int> LPS(temp.length(), 0); 
        computeLPS(temp, LPS);
        int longestLPSLength = LPS[temp.length()-1];
        string temp1 = rev.substr(0, s.length() - longestLPSLength);
        return temp1 + s;
    }
};
