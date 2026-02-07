class Solution {
public:
    int dp[101];
    int solve(string &s, int idx){
        int n = s.size();
        if(dp[idx] != -1) return dp[idx];
        if(idx == n) return 1;
        if(s[idx] == '0') return 0;
        int ways = 0;
        if(idx + 1 < n){
            int num = (s[idx] - '0') * 10 + (s[idx+1]-'0');
            if(num >= 10 && num <= 26){
                ways += solve(s, idx+2);
            }
        }
        ways += solve(s, idx+1);
        return dp[idx] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};