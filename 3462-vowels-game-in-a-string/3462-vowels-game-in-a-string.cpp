class Solution {
public:
    bool isvowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(isvowel(s[i])) cnt++;
        }
        if(cnt == 0) return false;
        else if(cnt % 2 == 1){
            return true;
        } else {
            return true;
        }
    }
};