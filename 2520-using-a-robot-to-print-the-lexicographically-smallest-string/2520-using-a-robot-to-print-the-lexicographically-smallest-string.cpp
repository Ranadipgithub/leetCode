class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        stack<char> st;
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string res = "";
        char minChar = 'a';

        for (int i = 0; i < n; i++) {
            st.push(s[i]);
            freq[s[i] - 'a']--;

            while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
                minChar++;
            }

            while (!st.empty() && st.top() <= minChar) {
                res += st.top();
                st.pop();
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};
