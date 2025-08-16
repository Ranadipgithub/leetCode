class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        for (auto ch : s) mpp[ch]++;

        stack<char> st;
        vector<bool> seen(26, false);

        for (int i = 0; i < n; i++) {
            mpp[s[i]]--;

            if (seen[s[i] - 'a']) continue; 

            while (!st.empty() && st.top() > s[i] && mpp[st.top()] > 0) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }

        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end()); 
        return res;
    }
};
