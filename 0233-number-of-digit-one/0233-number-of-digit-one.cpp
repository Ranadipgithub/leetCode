class Solution {
public:
    int dp[11][2][2][11];
    int solve(string &s, int idx, bool tight, bool lz, int cnt){
        if(idx == s.size()) return cnt;
        if(dp[idx][tight][lz][cnt] != -1) return dp[idx][tight][lz][cnt];
        int lb = 0;
        int ub = tight == 1? s[idx]-'0': 9;
        int res = 0;
        for(int dig = lb;dig<=ub;dig++){
            if(dig == 1){
                res += solve(s, idx+1, (tight && dig == ub), (lz && dig == 0), cnt+1);
            } else {
                res += solve(s, idx+1, (tight && dig == ub), (lz && dig == 0), cnt);
            }
        }
        return dp[idx][tight][lz][cnt] = res;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 1, 0);
    }
};