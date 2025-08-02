class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> maxRow(n, INT_MIN);
        for (int i = 0; i < n; i++) {
            maxRow[i] = *max_element(grid[i].begin(), grid[i].end());
        }

        vector<int> maxCol(m, INT_MIN);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int allowedHeight = min(maxRow[i], maxCol[j]);
                sum += (allowedHeight - grid[i][j]);
            }
        }

        return sum;
    }
};