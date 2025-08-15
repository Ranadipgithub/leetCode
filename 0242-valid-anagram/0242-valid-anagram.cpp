class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {0};
        for (char ch : s) freq[ch - 'a']++;
        for (char ch : t) {
            if (--freq[ch - 'a'] < 0) return false;
        }
        return true;
    }
};
