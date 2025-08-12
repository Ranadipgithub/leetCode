class Solution {
public:
    int dp[101][101][202];
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k){
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(i == n1 && j == n2 && k == n3){
            return true;
        }
        if(k == n3) return false;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(s3[k] == s1[i] && s3[k] == s2[j]){
            return dp[i][j][k] = solve(s1, s2, s3, i+1, j, k+1) || solve(s1, s2, s3, i, j+1, k+1);
        } else if(s3[k] == s1[i]){
            return dp[i][j][k] = solve(s1, s2, s3, i+1, j, k+1);
        } else if(s3[k] == s2[j]){
            return dp[i][j][k] = solve(s1, s2, s3, i, j+1, k+1);
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0 , 0);
    }
};