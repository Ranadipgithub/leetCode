class Solution {
public:
    const int mod = 1e9+7;
    int dp[100001][2][3][2];
    int solve(int n, int l, int e, int t){
        if(n == 0){
            if(l == 0 && e == 0 && t == 0) return 1;
            return 0;
        }
        if(dp[n][l][e][t] != -1) return dp[n][l][e][t];
        long long ways = 0;
        for(int i = 0;i<26;i++){
            char ch = 'a' + i;
            if(ch == 'l' && l > 0){
                ways = (ways + solve(n-1, l-1, e, t))%mod;
            } else if(ch == 'e' && e > 0){
                ways = (ways + solve(n-1, l, e-1, t))%mod;
            } else if (ch == 't' && t > 0){
                ways = (ways + solve(n-1, l, e, t-1))%mod;
            } else {
                ways = (ways + solve(n-1, l, e, t))%mod;
            }
        }
        return dp[n][l][e][t] = ways;
    }
    int stringCount(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 1, 2, 1);
    }
};