class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    const int MOD = 1e9 + 7;

    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int count = 1; 

        for (auto& dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            if (newi >= 0 && newi < matrix.size() && newj >= 0 && newj < matrix[0].size()
                && matrix[newi][newj] > matrix[i][j]) {
                count = (count + dfs(matrix, newi, newj, dp)) % MOD;
            }
        }

        dp[i][j] = count;
        return count;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int total = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                total = (total + dfs(grid, i, j, dp)) % MOD;
            }
        }

        return total;
    }
};
