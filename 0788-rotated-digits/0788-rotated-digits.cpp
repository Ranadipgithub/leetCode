class Solution {
public:
    bool isValid(int num){
        string s = to_string(num);
        int valid = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '3' || s[i] == '4' || s[i] == '7') return false;
            if(s[i] == '6' || s[i] == '9' || s[i] == '2' || s[i] == '5') valid++;
        }
        if(!valid) return false;
        return true;
    }
    int rotatedDigits(int n) {
        // all digits are 0,1 and 8 and their combination
        // 0,1,8 and 3, 4, 7  any combination
        // any combination of 3, 4, 7
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(isValid(i)){
                cnt++;
            }
        }
        return cnt;
    }
};