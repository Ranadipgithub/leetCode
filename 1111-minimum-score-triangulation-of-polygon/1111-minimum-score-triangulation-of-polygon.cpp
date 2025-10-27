class Solution {
public:
    int dp[51][51];
    int solve(int i, int j, vector<int>&values){
        if(j-i<2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int score = INT_MAX;
        for(int k = i+1;k<j;k++){
            int res = values[i]*values[j]*values[k] + solve(i, k, values) + solve(k, j, values);
            score = min(score, res);
        }
        return dp[i][j] = score;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, values.size()-1, values);
    }
};