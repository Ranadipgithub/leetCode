class Solution {
public:
    const int mod = 1e9+7;
    int dp[1001][1001][2];
    int solve(int zero, int one, int limit, int last){
        if(zero < 0 || one < 0) return 0;
        if(zero == 0 && one == 0) return 1;

        if(dp[zero][one][last] != -1)
            return dp[zero][one][last];

        long long ans = 0;

        if(last == 1){
            for(int i = 1;i<=min(zero, limit); i++){
                ans = (ans + solve(zero-i, one, limit, 0)) % mod;
            }
        }

        if(last == 0){
            for(int i = 1;i<=min(one, limit);i++){
                ans = (ans + solve(zero, one-i, limit, 1))%mod;
            }
        }

        return dp[zero][one][last] = ans % mod;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        long long ans = 0;

        for (int i = 1; i <= min(zero, limit); i++) {
            ans = (ans + solve(zero - i, one, limit, 0)) % mod;
        }
        for (int i = 1; i <= min(one, limit); i++) {
            ans = (ans + solve(zero, one - i, limit, 1)) % mod;
        }

        return ans % mod;
    }
};