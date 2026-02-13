class Solution {
public:
    int n, m;
    int dp[1001][1001];
    vector<vector<int>> directions{{-1, 1}, {0, 1}, {1, 1}};
    int solve(int i, int j, vector<vector<int>> &grid){

        if(dp[i][j] != -1) return dp[i][j];
        int maxCnt = 0;
        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];

            if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;

            if(grid[newi][newj] > grid[i][j]){
                int cnt = 1 + solve(newi, newj, grid);
                maxCnt = max(maxCnt, cnt);
            }
        }
        return dp[i][j] = maxCnt;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int moves = 0;
        for(int i = 0;i<n;i++){
            moves = max(moves, solve(i, 0, grid));
        }
        return moves;
    }
};