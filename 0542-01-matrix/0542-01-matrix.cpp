class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        vector<vector<int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;

        // Start BFS from all 0s
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(auto& dir : direction) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return dist;
    }
};
