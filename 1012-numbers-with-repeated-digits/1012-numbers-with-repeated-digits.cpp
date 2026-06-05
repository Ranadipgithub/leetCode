class Solution {
public:
    // returns the no of strings without repeated digits
    int dp[1024][11][2][2];
    int solve(string &s, int mask, int idx, bool tight, bool lz){
        // we are correctly able to form the string without repeating digits
        if(idx == s.size()) return 1;
        if(dp[mask][idx][tight][lz] != -1) return dp[mask][idx][tight][lz];
        int lb = 0, ub = tight == 1? s[idx]-'0': 9;
        int res = 0;
        for(int dig = lb;dig<=ub;dig++){
            int temp = 1 << dig;
            if((temp & mask) != 0){
                // the digit is repeated so we can't take this anymore
                continue;
            } else if(dig == 0 && lz){
                // for eg 040 it is unique, but if we mark the leading 0 in the mask
                // this will mark the no as non unique, so if the digit is 0 and it is
                // a leading 0 just move the mask forward without updating it
                res += solve(s, mask, idx+1, (tight && dig == ub), (lz && dig == 0));
            } else {
                res += solve(s, mask | (1<<dig), idx+1, (tight && dig == ub), (lz && dig == 0));
            }
        }
        return dp[mask][idx][tight][lz] = res;
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        int mask = 0;
        // total unique no from [1, n] = solve() - 1(removing the 0);
        // no of digit with atleast one repeated digit = n - (solve()-1) = n+1-solve()
        return n + 1 - solve(s, mask, 0, 1, 1);
    }
};