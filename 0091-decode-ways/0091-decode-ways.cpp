class Solution {
public:
    int dp[101];

    int solve(string s, int n, int idx){
        if(idx == n) return 1;
        if(dp[idx] != -1) return dp[idx];

        int cnt = 0;
        if(s[idx] != '0') {
            cnt += solve(s, n, idx+1);
            if(idx + 1 < n){
                string news = s.substr(idx, 2);
                if(stoi(news) <= 26){
                    cnt += solve(s, n, idx+2);
                }
            }
        }

        return dp[idx] = cnt;
    }

    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        if(s[0] == '0') return 0;

        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                if(s[i-1] != '1' && s[i-1] != '2') return 0;
            }
        }

        return solve(s, n, 0);
    }
};
