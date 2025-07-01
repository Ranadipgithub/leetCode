class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int cnt = 1, total = 0;
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
            } else {
                if (cnt > 1) {
                    total += (cnt - 1);
                }
                cnt = 1;
            }
        }
        if (cnt > 1) total += (cnt - 1); 
        return total + 1;
    }
};