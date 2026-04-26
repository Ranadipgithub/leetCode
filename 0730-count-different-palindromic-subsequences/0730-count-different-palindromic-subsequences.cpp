class Solution {
public:
    int prev[4][1001];
    int next[4][1001];
    int dp[1001][1001];
    const int mod = 1e9+7;
    int solve(int i, int j, string &s){
        int cnt = 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int c = 0;c<4;c++){
            int l = next[c][i];
            int r = prev[c][j];

            if(l != -1 && l <= j){
                if(l == r){
                    cnt = (cnt + 1)%mod;
                } else {
                    cnt = (cnt + 2 + solve(l+1, r-1, s))%mod;
                }
            }
        }
        return dp[i][j] = cnt;
    }
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        for(int c = 0;c<4;c++){
            int target = c + 'a';
            int last = -1;
            for(int i = 0;i<n;i++){
                if(s[i] == target) last = i;
                prev[c][i] = last;
            }
            int first = -1;
            for(int i = n-1;i>=0;i--){
                if(s[i] == target) first = i;
                next[c][i] = first;
            }
        }
        return solve(0, n-1, s);
    }
};