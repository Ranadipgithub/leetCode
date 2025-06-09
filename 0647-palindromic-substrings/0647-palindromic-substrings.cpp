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
        // for(int i = 0;i<n;i++){
        //     for(int j = i;j<n;j++){
        //         if(checkPalindrome(s, i, j)) cnt++;
        //     }
        // }

        vector<vector<bool>>t(n, vector<bool>(n, 0));
        for(int l = 1;l<=n;l++){
            for(int i = 0; i+l-1 < n;i++){
                int j = i+l-1;
                if(i == j){
                    t[i][j] = true;
                } else if(i+1 == j){
                    t[i][j] = (s[i] == s[j]);
                } else{
                    t[i][j] = s[i] == s[j] && t[i+1][j-1];
                }

                if(t[i][j]) cnt++;
            }
        }
        return cnt;
    }
};