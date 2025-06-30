class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i =0, j = 0;
        int maxLen = 0;
        unordered_map<char, int> fq;
        int maxf = 0;
        while(j<n){
            fq[s[j]]++;
            maxf = max(maxf, fq[s[j]]);
            if((j-i+1)-maxf <= k){
                maxLen = max(maxLen, j-i+1);
                j++;
            } else{
                while((j-i+1) - maxf > k){
                    fq[s[i]]--;
                    if(fq[s[i]] == 0) fq.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxLen;
    }
};