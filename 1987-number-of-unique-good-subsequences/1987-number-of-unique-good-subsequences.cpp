class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfUniqueGoodSubsequences(string s) {
        int n = s.size();
        vector<int> temp(n, 1), dp(n, 1);
        int last0 = s[n-1] == '0'? n-1: -1, last1 = s[n-1] == '1'? n-1: -1;
        for(int i = n-2;i>=0;i--){
            if(s[i] == '0'){
                int sub = 0;
                if(last0 == -1){
                    dp[i] = (dp[i+1] + 1)%MOD;
                } else {
                    dp[i] = dp[i+1];
                }
            } else {
                int sub = 0;
                if(last1 != -1){
                    sub = (1 + (last1 +1 < n? temp[last1+1]: 0)+MOD)%MOD;
                }
                dp[i] = (dp[i+1] + temp[i+1] + 1 - sub + MOD)%MOD;
            }
            int sub = 0;
            if(s[i] == '0' && last0 != -1) sub = (1 + (last0 + 1 < n ? temp[last0+1] : 0)) % MOD;
            if(s[i] == '1' && last1 != -1) sub = (1 + (last1 + 1 < n ? temp[last1+1] : 0)) % MOD;
            temp[i] = (2LL*temp[i+1] + 1 - sub + MOD)%MOD;
            if(s[i] == '0') last0 = i;
            else last1 = i;
        }
        return dp[0];
    }
};