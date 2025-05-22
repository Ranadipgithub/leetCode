class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (int i = 0; i < n - 1; i++) {
            dist[i][i + 1] = 1;
            dist[i + 1][i] = 1;
        }

        x--; y--;
        dist[x][y] = 1;
        dist[y][x] = 1;

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        vector<int> res(n, 0); 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = dist[i][j];
                if (d > 0 && d <= n) {
                    res[d - 1] += 2; 
                }
            }
        }

        return res;
    }
};
