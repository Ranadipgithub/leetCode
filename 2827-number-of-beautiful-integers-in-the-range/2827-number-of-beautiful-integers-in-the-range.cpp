class Solution {
public:
    int dp[12][2][2][12][12][22];
    int solve(string &s, int idx, int tight, int lz, int k, int even, int odd, int num){
        if(idx == s.size()){
            if(!lz && num == 0 && even == odd) return 1;
            return 0;
        }
        if(dp[idx][tight][lz][even][odd][num] != -1) return dp[idx][tight][lz][even][odd][num];
        int lb = 0;
        int ub = tight == 1? s[idx]-'0': 9;
        int res = 0;
        for(int dig = lb;dig<=ub;dig++){
            int newOdd = odd + dig%2;
            int newEven = even + ((lz && dig == 0)? 0: (dig%2 == 0));
            res += solve(s, idx+1, tight && dig == s[idx]-'0', lz && dig == 0, k, newEven, newOdd, (num*10 + dig)%k);
        }
        return dp[idx][tight][lz][even][odd][num] = res;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1 = to_string(high);
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(s1, 0, 1, 1, k, 0, 0, 0);
        string s2 = to_string(low-1);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(s2, 0, 1, 1, k, 0, 0, 0);
        return ans1 - ans2;
    }
};