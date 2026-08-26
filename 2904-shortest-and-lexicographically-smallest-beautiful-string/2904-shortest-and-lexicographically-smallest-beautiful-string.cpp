class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0, minLen = n;
        string ans = "";
        while(j < n){
            if(s[j] == '1'){
                cnt++;
            }
            while(cnt > k){
                if(s[i] == '1') cnt--;
                i++;
            }
            if(cnt == k){
                while(s[i] == '0') i++;
                string temp = s.substr(i, j-i+1);
                if(ans == ""){
                    ans = temp;
                    minLen = j-i+1;
                } 
                else if(j-i+1 < minLen){
                    minLen = j-i+1;
                    ans = temp;
                } else if(j-i+1 == minLen){
                    ans = min(ans, temp);
                }
            }
            j++;
        }
        return ans;
    }
};