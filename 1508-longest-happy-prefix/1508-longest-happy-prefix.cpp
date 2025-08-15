class Solution {
public:
    void findLPS(string &needle, vector<int> &lps, int m) {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) {
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
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        findLPS(s, lps, n);
        int len = lps[n - 1]; 
        return s.substr(0, len);
    }
};