class Solution {
public:
    bool check(vector<vector<int>>& grid, int si, int sj, int k) {
        int target = 0;

        for (int j = sj; j < sj + k; j++) {
            target += grid[si][j];
        }

        for (int i = si; i < si + k; i++) {
            int rowSum = 0;
            for (int j = sj; j < sj + k; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != target) return false;
        }

        for (int j = sj; j < sj + k; j++) {
            int colSum = 0;
            for (int i = si; i < si + k; i++) {
                colSum += grid[i][j];
            }
            if (colSum != target) return false;
        }

        int diag1 = 0, diag2 = 0;
        for (int d = 0; d < k; d++) {
            diag1 += grid[si + d][sj + d];
            diag2 += grid[si + d][sj + k - d - 1];
        }

        if (diag1 != target || diag2 != target) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 1; i + k <= n && j + k <= m; k++) {
                    if (check(grid, i, j, k)) {
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
    }
};