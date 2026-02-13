class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{1, -1}, {1, 0}, {1, 1}};
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& matrix){
        if(i < 0 || i >= n || j <0 || j >= m) return 1e9;
        if(i == n-1) return matrix[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int minSum = 1e9;
        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];

            int sum = matrix[i][j] + solve(newi, newj, matrix);
            minSum = min(minSum, sum);
        }
        return dp[i][j] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = INT_MAX;
            }
        }

        int sum = INT_MAX;
        for(int j = 0;j<m;j++){
            sum = min(sum, solve(0, j, matrix));
        }

        return sum;
    }
};