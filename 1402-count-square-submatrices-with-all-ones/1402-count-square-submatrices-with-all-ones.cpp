class Solution {
public:
    int dp[301][301];
    int solve(vector<vector<int>>& matrix, int i, int j){
        int n = matrix.size();
        int m = matrix[0].size();
        if(i>=n || j >= m || matrix[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(matrix, i, j+1);
        int diag = solve(matrix, i+1, j+1);
        int bottom = solve(matrix, i+1, j);
        return dp[i][j] = 1 + min({right, diag, bottom});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0) continue;
                cnt += solve(matrix, i, j);
            }
        }
        return cnt;
    }
};