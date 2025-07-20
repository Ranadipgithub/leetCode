class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;
        int maxCnt = 0;
        int i = 0, j = 0;
        while(j<n){
            if(isVowel(s[j])){
                cnt++;
            }
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                maxCnt = max(maxCnt, cnt);
                if(isVowel(s[i])){
                    if(cnt > 0) cnt--;
                }
                i++;
                j++;
            }
        }
        return maxCnt;
    }
};