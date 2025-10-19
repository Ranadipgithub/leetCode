class Solution {
public:
    string add(string s, int a) {
        int n = s.size();
        for(int i = 1; i < n; i += 2) {
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        }
        return s;
    }

    string rotate(string s, int b) {
        int n = s.size();
        b %= n;
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        return s;
    }

    void dfs(string s, int a, int b, string &res, unordered_set<string> &vis) {
        if(vis.count(s)) return;
        vis.insert(s);
        res = min(res, s);
        dfs(add(s, a), a, b, res, vis);
        dfs(rotate(s, b), a, b, res, vis);
    }

    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        unordered_set<string> vis;
        dfs(s, a, b, res, vis);
        return res;
    }
};