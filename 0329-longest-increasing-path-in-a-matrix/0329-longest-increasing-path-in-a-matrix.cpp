class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int maxLen = 1;

        for (auto& dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            if (newi >= 0 && newi < matrix.size() && newj >= 0 && newj < matrix[0].size()
                && matrix[newi][newj] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(matrix, newi, newj, dp));
            }
        }

        dp[i][j] = maxLen;
        return maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxCnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxCnt = max(maxCnt, dfs(matrix, i, j, dp));
            }
        }

        return maxCnt;
    }
};
