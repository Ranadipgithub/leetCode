class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        int no = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i > 0 && mpp[s[i]] > mpp[s[i - 1]]) {  
                no += mpp[s[i]] - mpp[s[i - 1]];
                i--;
            } else {
                no += mpp[s[i]];
            }
        }

        return no;
    }
};