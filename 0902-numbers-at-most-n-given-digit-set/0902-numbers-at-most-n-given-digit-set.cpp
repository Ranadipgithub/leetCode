class Solution {
public:
    int dp[1024][10][2][2];
    int solve(string &s, int mask, int idx, bool tight, bool lz){
        if(idx == s.size()) return 1;
        int lb = 0;
        int ub = (tight == 1)? s[idx]-'0': 9;
        int res = 0;
        if(dp[mask][idx][tight][lz] != -1) return dp[mask][idx][tight][lz];
        for(int dig = lb; dig <= ub; dig++){
            if(lz && dig == 0){
                res += solve(s, mask, idx+1, (tight && (dig == s[idx] - '0')), (lz && dig == 0));
            } else if(((1 << dig) & mask)){
                res += solve(s, mask, idx+1, (tight && (dig == s[idx] - '0')), (lz && dig == 0));
            }
        }
        return dp[mask][idx][tight][lz] = res;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int mask = 0;
        for(string &dig: digits){
            mask |= (1 << stoi(dig));
        }
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, mask, 0, 1, 1) - 1;
    }
};