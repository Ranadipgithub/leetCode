class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        vector<bool> seen(26, false);
        string st; 
        for (char c : s) {
            freq[c - 'a']--;
            if (seen[c - 'a']) continue;
            while (!st.empty() && st.back() > c && freq[st.back() - 'a'] > 0) {
                seen[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            seen[c - 'a'] = true;
        }
        return st;
    }
};