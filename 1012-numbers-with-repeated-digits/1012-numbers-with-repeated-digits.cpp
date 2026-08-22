class Solution {
public:
    int dp[10][2][2][1024];
    int solve(string &s, int idx, bool tight, bool lz, int mask){
        if(idx == s.size()) return 1;
        int lb = 0;
        int ub = (tight == 1) ? s[idx] - '0': 9;
        int res = 0;
        if(dp[idx][tight][lz][mask] != -1) return dp[idx][tight][lz][mask];
        for(int dig = lb;dig <= ub;dig++){
            int temp = 1 << dig;
            if((temp & mask) != 0){
                continue;
            } else if(dig == 0 && lz){
                res += solve(s, idx+1, (tight & dig == ub), (lz && dig == 0), mask);
            } else {
                res += solve(s, idx+1, (tight & dig == ub), (lz && dig == 0), mask | (1 << dig));
            }
        }
        return dp[idx][tight][lz][mask] = res;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int mask = 0;
        memset(dp, -1, sizeof(dp));
        return n+1 - solve(s, 0, 1, 1, mask);
    }
};