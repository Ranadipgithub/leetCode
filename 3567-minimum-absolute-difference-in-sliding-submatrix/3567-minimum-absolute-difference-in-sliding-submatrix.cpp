class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int x = m - k + 1, y = n - k + 1;
        vector<vector<int>> res(x, vector<int>(y, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                set<int> s;
                for (int p = 0; p < k; p++) {
                    for (int q = 0; q < k; q++) {
                        s.insert(grid[i + p][j + q]);
                    }
                }
                if (s.size() < 2) continue;
                auto prev = s.begin();
                auto curr = next(prev);
                int best = INT_MAX;
                while (curr != s.end()) {
                    best = min(best, *curr-*prev);
                    prev = curr++;
                }
                res[i][j] = best;
            }
        }
        return res;
    }
};
