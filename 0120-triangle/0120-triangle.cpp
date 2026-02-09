class Solution {
public:
    int dp[205][205];
    int solve(int i, int j, vector<vector<int>>& triangle){
        int n = triangle.size();
        if(i >= n){
            return 0;
        }
        if(dp[i][j] != -1e9) return dp[i][j];
        int op1 = triangle[i][j] + solve(i+1, j, triangle);
        int op2 = triangle[i][j] + solve(i+1, j+1, triangle);
        return dp[i][j] = min(op1, op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=n;j++){
                dp[i][j] = -1e9;
            }
        }
        return solve(0, 0, triangle);
    }
};