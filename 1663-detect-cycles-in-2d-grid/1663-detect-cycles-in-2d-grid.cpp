class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(vector<vector<char>>& grid, int i, int j, char color, int pi, int pj) {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;

        for (auto &dir : direction) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            if (newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
            if (grid[newi][newj] != color) continue;
            if (newi == pi && newj == pj) continue;
            if (visited[newi][newj]) return true;
            if (dfs(grid, newi, newj, color, i, j)) return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.assign(n, vector<int>(m, 0)); 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, grid[i][j], -1, -1)) return true;
                }
            }
        }
        return false;
    }
};
