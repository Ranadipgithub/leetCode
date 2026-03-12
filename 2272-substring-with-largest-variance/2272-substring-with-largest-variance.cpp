class Solution {
public:
    int solve(string &s, int i, int j){
        int n = s.size();
        char ch1 = 'a' + i, ch2 = 'a'+j;
        int ch1cnt =0, ch2cnt = 0;
        int maxi = 0;
        bool fg = false;
        for(int i = 0;i<n;i++){
            if(s[i] == ch1) ch1cnt++;
            else if(s[i] == ch2) ch2cnt++;

            if(ch2cnt > 0){
                maxi = max(maxi, ch1cnt-ch2cnt);
            } else if (fg){
                maxi = max(maxi, ch1cnt-1);
            }

            if(ch1cnt < ch2cnt){
                ch1cnt = 0;
                ch2cnt = 0;
                fg = true;
            }
        }
        return maxi;
    }
    int largestVariance(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i = 0;i<26;i++){
            for(int j = 0;j<26;j++){
                int ans = solve(s, i, j);
                maxi = max(maxi, ans);
            }
        }
        return maxi;
    }
};