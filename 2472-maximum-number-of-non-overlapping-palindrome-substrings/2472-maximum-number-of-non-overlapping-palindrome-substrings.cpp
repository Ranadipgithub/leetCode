class Solution {
public:
    int dp[2001];
    int solve(int idx, vector<vector<bool>>&t, int k){
        if(idx == t.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = solve(idx+1, t, k);
        for(int j = idx+k-1;j<t.size();j++){
            if(t[idx][j]) ans = max(ans, 1 + solve(j+1, t, k));
        }
        return dp[idx] = ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<bool>>t(n, vector<bool>(n, 0));
        for(int l = 1;l<=n;l++){
            for(int i = 0; i+l-1 < n;i++){
                int j = i+l-1;
                if(i == j){
                    t[i][j] = true;
                } else if(i+1 == j){
                    t[i][j] = (s[i] == s[j]);
                } else{
                    t[i][j] = s[i] == s[j] && t[i+1][j-1];
                }
            }
        }
        // for(int i = 0;i<n;i++){
        //     for(int j = i;j<n;j++){
        //         cout << t[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return solve(0, t, k);
    }
};