class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) words.push_back(word); 

        reverse(words.begin(), words.end());

        string ans;
        for (int i = 0; i < words.size(); ++i) {
            ans += words[i];
            if (i != words.size() - 1) ans += " ";
        }

        return ans;
    }
};