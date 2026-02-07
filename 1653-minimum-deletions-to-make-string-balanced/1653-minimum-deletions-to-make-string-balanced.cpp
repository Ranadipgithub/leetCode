class Solution {
public:
    int dp[2][100001];
    int solve(string &s, char next, int idx){
        int n = s.size();
        if(idx == n) return 0;
        if(dp[next - 'a'][idx] != -1) return dp[next - 'a'][idx];
        int take = 0;
        if(next == 'a'){
            if(s[idx] == 'a'){
                take = 1 + solve(s, 'a', idx+1);
            } else {
                take = 1 + solve(s, 'b', idx+1);
            }
        } else {
            if(s[idx] == 'b'){
                take = 1 + solve(s, next, idx + 1);
            }
        }
        int skip = solve(s, next, idx+1);
        return dp[next - 'a'][idx] = max(take, skip);
    }
    int minimumDeletions(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(s, 'a', 0);
        return n - ans;
    }
};