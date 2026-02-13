class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{1, -1}, {1, 0}, {1, 1}};
    int dp[71][71][71];
    int solve(int i, int j1, int j2, vector<vector<int>>& grid){
        if(i == n-1) return j1 == j2? grid[i][j1]: grid[i][j1] + grid[i][j2];
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int cnt = 0;
        for(auto &dir1: directions){
            for(auto &dir2: directions){
                int newi = i + 1;
                int newj1 = j1 + dir1[1];
                int newj2 = j2 + dir2[1];

                if(newi < 0 || newi >= n || newj1 < 0 || newj1 >= m || newj2 < 0 || newj2 >= m) continue;
                int temp = 0;
                if(j1 != j2){
                    temp = grid[i][j1] + grid[i][j2] + solve(newi, newj1, newj2, grid);
                    cnt = max(cnt, temp);
                } else {
                    temp = grid[i][j1] + solve(newi, newj1, newj2, grid);
                    cnt = max(cnt, temp);
                }
            }
        }
        return dp[i][j1][j2] = cnt;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, m-1, grid);
    }
};