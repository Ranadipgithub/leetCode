class Solution {
public:
    int dp[23][2][200];
    const int mod = 1e9+7;
    int solve(string &s, int idx, int tight, int curr, int min_sum, int max_sum){
        if(idx == s.size()){
            return curr <= max_sum && curr >= min_sum;
        }
        if(dp[idx][tight][curr] != -1) return dp[idx][tight][curr];
        int lb = 0;
        int ub = tight == 1? s[idx]-'0': 9;
        int res = 0;
        for(int dig = lb;dig <= ub;dig++){
            res = (res + solve(s, idx+1, (tight && dig == s[idx]-'0'), curr+dig, min_sum, max_sum))%mod;
        }
        return dp[idx][tight][curr] = res%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(num1, 0, 1, 0, min_sum, max_sum);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(num2, 0, 1, 0, min_sum, max_sum);
        int sum = 0;
        for(char c: num1) sum += c - '0';
        int add = sum >= min_sum && sum <= max_sum;
        return (ans2 - ans1 + add + mod)%mod;
    }
};