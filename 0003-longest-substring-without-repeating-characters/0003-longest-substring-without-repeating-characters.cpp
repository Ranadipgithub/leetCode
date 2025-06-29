class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        unordered_map<char, int> mpp;
        int i = 0, j = 0;
        while (j < n) {
            mpp[s[j]]++;
            if(mpp.size() == j-i+1){
                maxLen = max(maxLen, j-i+1);
            }
            else if(mpp.size() < j-i+1){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            j++;
        }
        return maxLen;
    }
};