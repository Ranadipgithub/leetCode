class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        int n = s.size();
        map<int, int>mpp;
        for(int i = 0;i<n;i++){
            mpp[s[i]]++;
        }
        int fqV=0, fqC = 0;
        int maxfqc=0, maxfqv = 0;
        for(int i = 0;i<n;i++){
            if(isVowel(s[i])){
                fqV = mpp[s[i]];
                maxfqv = max(maxfqv,fqV);
            } else{
                fqC = mpp[s[i]];
                maxfqc = max(maxfqc, fqC);
            }
        }
        return maxfqv+maxfqc;
    }
};