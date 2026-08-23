class Solution {
public:
    long long dp[16][2];
    long long solve(string &s, int limit, int idx, bool tight){
        if(idx == s.size()) return 1;
        int lb = 0;
        int ub = tight == 1 ? min((int)(s[idx]-'0'), limit) : limit;
        long long res = 0;
        if(dp[idx][tight] != -1) return dp[idx][tight];
        for(int dig = lb;dig<=ub;dig++){
            res += solve(s, limit, idx+1, tight && dig == s[idx]-'0');
        }
        return dp[idx][tight] = res;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // 60000 __124
        for(char c : s) {
            if(c - '0' > limit) return 0;
        }

        long long p10 = 1;
        for(int i = 0;i<s.size();i++) p10 *= 10;
        long long ans1 = 0;
        // x <= finish => P*10^m + s <= finish => p <= (finish - s)/10^m
        long long sval = stoll(s);
        if(finish >= sval){
            string temp = to_string((finish-sval)/p10);
            memset(dp, -1, sizeof(dp));
            ans1 = solve(temp, limit, 0, 1);
        }
        // x >= start - 1 => P*10^m + s >= start-1 => p >= (start-1-s)/10^m
        long long ans2 = 0;
        if(start -1 >= sval){
            string temp2 = to_string((start - 1 - sval) / p10);
            memset(dp, -1, sizeof(dp));
            ans2 = solve(temp2, limit, 0, 1);
        }
        return ans1 - ans2;
    }
};