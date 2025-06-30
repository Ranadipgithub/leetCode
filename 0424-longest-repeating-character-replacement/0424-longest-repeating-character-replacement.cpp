class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int maxf = INT_MIN, maxLen = 0;;
        while(j<n){
            mpp[s[j]]++;
            maxf = max(maxf, mpp[s[j]]);
            if(j-i+1-maxf <= k){
                maxLen = max(maxLen, j-i+1);
                j++;
            } else{
                while(j-i+1 - maxf > k){
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxLen;
    }
};