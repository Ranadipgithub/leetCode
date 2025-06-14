class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int seen = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                seen = s[i];
                break;
            }
        }
        if (seen != -1) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == seen) s[i] = '9';
            }
        }

        string s2 = to_string(num);
        char min_ch = s2[0];
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == min_ch) s2[i] = '0';
        }

        int num1 = stoi(s);
        int num2 = stoi(s2);
        return num1 - num2;
    }
};
