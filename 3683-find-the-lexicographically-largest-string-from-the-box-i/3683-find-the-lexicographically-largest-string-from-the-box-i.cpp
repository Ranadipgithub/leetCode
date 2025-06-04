class Solution {
public:
    string res;
    vector<vector<int>> dp;

    void solve(const string &s, int n, int m, int idx) {
        if (m == 1) {
            string temp = s.substr(idx);
            if (temp > res) res = temp;
            return;
        }

        if (dp[m][idx] != -1) return;

        for (int cut = idx + 1; cut <= n - (m - 1); ++cut) {
            string temp = s.substr(idx, cut - idx);
            if (temp > res) res = temp;
            solve(s, n, m - 1, cut);
        }

        dp[m][idx] = 1; 
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        string res;
        for (int i = 0; i < n; i++) {
            res = max(res, word.substr(i, min(n - numFriends + 1, n - i)));
        }
        return res;
    }
};
