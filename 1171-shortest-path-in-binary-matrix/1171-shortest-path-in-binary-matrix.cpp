class Solution {
public:
    vector<vector<int>> directions{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> explored(n, vector<int>(m, 0));

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first, i = it.second.first, j = it.second.second;
            if (explored[i][j] == 1) continue;
            explored[i][j] = 1;

            if (i == n - 1 && j == n - 1) return dis;

            for (auto &dir : directions) {
                int newi = i + dir[0];
                int newj = j + dir[1];
                if (newi < 0 || newi >= n || newj < 0 || newj >= n) continue;
                if (grid[newi][newj] == 1 || explored[newi][newj]) continue;
                if (dis + 1 < dist[newi][newj]) {
                    dist[newi][newj] = dis + 1;
                    q.push({dist[newi][newj], {newi, newj}});
                }
            }
        }
        return -1;
    }
};
