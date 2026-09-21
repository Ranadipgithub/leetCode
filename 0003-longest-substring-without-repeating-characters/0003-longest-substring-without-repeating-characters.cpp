class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        while(j < n){
            if(mpp.count(s[j])){
                i = max(i, mpp[s[j]] + 1);
            } 
            maxLen = max(maxLen, j-i+1);
            
            mpp[s[j]] = j;
            j++;
        }
        return maxLen;
    }
};