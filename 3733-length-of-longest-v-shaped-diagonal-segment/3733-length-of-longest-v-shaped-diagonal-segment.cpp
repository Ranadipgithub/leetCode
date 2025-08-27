class Solution {
public:
    vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int m, n;
    int t[501][501][4][2];
    int solve(int i, int j, int d, bool canTurn, int val, vector<vector<int>>& grid) {
        int newi = i + directions[d][0];
        int newj = j + directions[d][1];

        if(newi < 0 || newi >= m || newj < 0 || newj >= n || grid[newi][newj] != val) {
            return 0;
        }

        if(t[newi][newj][d][canTurn] != -1) {
            return t[newi][newj][d][canTurn];
        }

        int result = 0;
        int op1 = 1 + solve(newi, newj, d, canTurn, val == 2 ? 0 : 2, grid);
        result = max(result, op1);

        if(canTurn == true) {
            int op2 = max(op1, 1 + solve(newi, newj, (d+1)%4, false, val == 2 ? 0 : 2, grid));
            result = max(result, op2);
        }

        return t[newi][newj][d][canTurn] = result;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));

        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int d = 0; d <= 3; d++) {
                        result = max(result, 1 + solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }
        return result;
    }
};