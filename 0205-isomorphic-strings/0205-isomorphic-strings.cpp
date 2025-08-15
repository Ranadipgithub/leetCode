class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if (n != t.size()) return false;

        unordered_map<char, char> mp1; // s -> t
        unordered_map<char, char> mp2; // t -> s

        for (int i = 0; i < n; i++) {
            if (mp1.count(s[i]) && mp1[s[i]] != t[i]) return false;
            if (mp2.count(t[i]) && mp2[t[i]] != s[i]) return false;
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};
