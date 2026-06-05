class Solution {
public:
    int dp[32][2][2][3];
    int solve(string &s, int idx, bool tight, bool lz, int prev){
        if(idx == s.size()) return 1;
        if(dp[idx][tight][lz][prev] != -1) return dp[idx][tight][lz][prev];
        int lb = 0;
        int ub = tight == 1? s[idx]-'0' : 1;
        int res = 0;
        for(int dig = lb;dig<=ub;dig++){
            if(prev == 1 && dig == 1) continue;
            res += solve(s, idx+1, (dig == ub && tight), (lz && dig == 0), dig);
        }
        return dp[idx][tight][lz][prev] = res;
    }
    int findIntegers(int n) {
        string s = "";
        while(n > 0){
            s += n%2 + '0';
            n /= 2;
        }
        memset(dp, -1, sizeof(dp));
        reverse(s.begin(), s.end());
        return solve(s, 0, 1, 1, 2);
    }
};