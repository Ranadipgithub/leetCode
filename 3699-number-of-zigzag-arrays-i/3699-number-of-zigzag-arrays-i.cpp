class Solution {
public:
    const int mod = 1e9+7;
    int dp[2001][2][2001];
    int n, l, r;
    int solve(int idx, bool isDecreasing, int prev){
        if(idx >= n) return 1;
        if(dp[idx][isDecreasing][prev] != -1) return dp[idx][isDecreasing][prev];
        int cnt = 0;
        if(isDecreasing){
            // prev pattern was decreasing so here it will be strictly increasing
            // for(int el = prev + 1;el<=r;el++){
            //     cnt = (cnt + solve(idx+1, false, el, n, l, r))%mod;
            // }
            if(prev < r)
                cnt = (solve(idx+1, false, prev+1) + solve(idx, true, prev+1))%mod;
        } else {
            // for(int el = l; el < prev; el++){
            //     cnt = (cnt + solve(idx+1, true, el, n, l, r))%mod;
            // }
            if(prev > l)
                cnt = (solve(idx+1, true, prev-1) + solve(idx, false, prev-1))%mod;
        }
        return dp[idx][isDecreasing][prev] = cnt%mod;
    }
    int zigZagArrays(int n, int l, int r) {
        this->n = n;
        this->l = l;
        this->r = r;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = l; j <= r; j++){
                dp[i][0][j] = -1;
                dp[i][1][j] = -1;
            }
        }
        for(int el = l;el<=r;el++){
            cnt = (cnt + solve(1, false, el))%mod;
            cnt = (cnt + solve(1, true, el))%mod;
        }
        return cnt%mod;
    }
};