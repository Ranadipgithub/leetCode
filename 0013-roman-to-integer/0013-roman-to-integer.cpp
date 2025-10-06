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
        for(int i = 0;i<n;i++){
            if(i<n-1 && mpp[s[i]] < mpp[s[i+1]]){
                no += mpp[s[i+1]] - mpp[s[i]];
                i++;
            } else {
                no += mpp[s[i]];
            }
        }
        return no;
    }
};