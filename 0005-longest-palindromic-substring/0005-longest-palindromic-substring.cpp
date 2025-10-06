class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1;
        if(n == 1) return s;
        string res = "";
        for(int i = 1;i<n-1;i++){
            int j = i-1, k = i+1;
            while(j>=0 && k<n){
                if(s[j] == s[k]){
                    if(k-j+1 > maxlen){
                        maxlen = k-j+1;
                        res = s.substr(j, k-j+1);
                    }
                    j--;
                    k++;
                } else{
                    break;
                }
            }
        }

        for(int i = 0;i<n-1;i++){
            int j = i, k = i+1;
            while(j>=0 && k<n){
                if(s[j] == s[k]){
                    if(k-j+1 > maxlen){
                        maxlen = k-j+1;
                        res = s.substr(j, k-j+1);
                    }
                    j--;
                    k++;
                } else {
                    break;
                }
            }
        }

        return maxlen == 1? s.substr(0, 1): res;
    }
};