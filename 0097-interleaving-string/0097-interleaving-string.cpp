class Solution {
public:
    int dp[101][101];
    bool solve(string &s1, string &s2, string &s3, int i, int j){
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(i == n1 && j == n2 && i+j == n3){
            return true;
        }
        if(i+j == n3) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s3[i+j] == s1[i] && s3[i+j] == s2[j]){
            return dp[i][j] = solve(s1, s2, s3, i+1, j) || solve(s1, s2, s3, i, j+1);
        } else if(s3[i+j] == s1[i]){
            return dp[i][j] = solve(s1, s2, s3, i+1, j);
        } else if(s3[i+j] == s2[j]){
            return dp[i][j] = solve(s1, s2, s3, i, j+1);
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0);
    }
};