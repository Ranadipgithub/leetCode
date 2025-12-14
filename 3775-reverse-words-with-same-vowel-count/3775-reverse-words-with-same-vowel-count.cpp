class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }

    string reverseWords(string s) {
        bool fg = false;
        int n = s.size();
        int sidx = 0, cnt = 0, curr = 0;

        for (int i = 0; i < n; i++) {
            if (!fg) {
                if (isVowel(s[i])) cnt++;
                if (s[i] == ' ') {
                    sidx = i;
                    fg = true;
                }
            } else {
                if (isVowel(s[i])) curr++;
                if (s[i] == ' ' || i == n - 1) {
                    if (curr == cnt) {
                        if(i == n-1)
                            reverse(s.begin() + sidx + 1, s.end());
                        else reverse(s.begin() + sidx + 1, s.begin()+i);
                    }
                    sidx = i;
                    curr = 0;
                }
            }
        }
        return s;
    }
};