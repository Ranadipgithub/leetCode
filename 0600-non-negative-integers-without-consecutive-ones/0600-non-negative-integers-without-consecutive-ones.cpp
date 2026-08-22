class Solution {
public:
    int dp[32][2][3];
    int solve(string &s, int idx, bool tight, int prev){
        if(idx == s.size()) return 1;
        int lb = 0;
        int ub = (tight == 1)? s[idx]-'0': 1;
        int res = 0;
        if(dp[idx][tight][prev] != -1) return dp[idx][tight][prev];
        for(int dig = lb;dig <= ub; dig++){
            if(dig == 1 && prev == 1) continue;
            res += solve(s, idx+1, (tight && dig == ub), dig);
        }
        return dp[idx][tight][prev] = res;
    }
    int findIntegers(int n) {
        string s = "";
        while(n > 0){
            s += n%2 + '0';
            n /= 2;
        }
        reverse(s.begin(), s.end());
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 2);
    }
};