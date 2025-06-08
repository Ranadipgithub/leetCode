class Solution {
public:
    int checkPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(checkPalindrome(s, i, j)) cnt++;
            }
        }
        return cnt;
    }
};