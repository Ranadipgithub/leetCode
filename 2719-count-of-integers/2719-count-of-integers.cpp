class Solution {
public:
    int dp[23][2][2][400];
    const int mod = 1e9 + 7;
    string subtractOne(string s) {
        int i = s.size() - 1;
        while(i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }
        if(i >= 0) s[i]--;
        return s;
    }
    int solve(string &s, int idx, int tight, int lz, int mini, int maxi, int curr){
        if(idx == s.size()){
            if(curr >= mini && curr <= maxi) return 1;
            return 0;
        }
        if(dp[idx][tight][lz][curr] != -1) return dp[idx][tight][lz][curr];
        int lb = 0, ub = tight == 1? s[idx]-'0': 9;
        int res = 0;
        for(int dig = lb;dig<=ub;dig++){
            if(lz && dig == 0){
                res = (res + solve(s, idx+1, (tight && dig == ub), (lz && dig == 0), mini, maxi, curr))%mod;
            } else {
                res = (res + solve(s, idx+1, (tight && dig == ub), (lz && dig == 0), mini, maxi, curr+dig))%mod;
            }
        }
        return dp[idx][tight][lz][curr] = res%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(num2, 0, 1, 1, min_sum, max_sum, 0);
        num1 = subtractOne(num1);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(num1, 0, 1, 1, min_sum, max_sum, 0);
        return ((ans1 - ans2)%mod + mod)%mod;
    }
};