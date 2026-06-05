class Solution {
public:
    typedef long long ll;
    long long dp[20][20][2][11][11][2];
    ll solve(string &s, ll idx, ll cnt, ll tight, ll prev1, ll prev2, bool lz){
        if(idx == s.size()){
            return cnt;
        }
        if(dp[idx][cnt][tight][prev1][prev2][lz] != -1) return dp[idx][cnt][tight][prev1][prev2][lz];

        ll lb = 0;
        ll ub = tight == 1? s[idx]-'0': 9;

        ll res = 0;
        for(ll dig = lb;dig<=ub;dig++){
            if(lz && dig == 0){
                res += solve(s, idx+1, cnt, (tight && dig == ub), 10, 10, 1);
            }
            else if(prev1 == 10 || prev2 == 10){
                res += solve(s, idx+1, cnt, (tight && dig == ub) , dig, prev1, 0);
            }
            else if ((prev1 > prev2 && prev1 > dig) || (prev1 < prev2 && prev1 < dig)){
                res += solve(s, idx+1, cnt+1, (tight && dig == ub) , dig, prev1, 0);
            } else {
                res += solve(s, idx+1, cnt, (tight && dig == ub) , dig, prev1, 0);
            }
        }
        return dp[idx][cnt][tight][prev1][prev2][lz] = res;
    }
    long long totalWaviness(long long num1, long long num2) {
        ll ans1 = 0;
        string l = to_string(num1-1);
        memset(dp, -1, sizeof(dp));
        ans1 = solve(l, 0, 0, 1, 10, 10, 1);

        string r = to_string(num2);
        memset(dp, -1, sizeof(dp));
        ll ans2 = solve(r, 0, 0, 1, 10, 10, 1);
        
        return ans2 - ans1;
    }
};