class Solution {
public:
    int n, m;
    int dp[101][101];
    int solve(int i, int j, vector<vector<int>>& grid){
        if(j >= m) return -1;
        if(i >= n) return j;
        if(dp[i][j] != -1) return dp[i][j];
        if(grid[i][j] == 1){
            if(j + 1 < m && grid[i][j+1] == 1){
                return dp[i][j] = solve(i+1, j+1, grid);
            } else {
                return -1;
            }
        } else {
            if(j-1 >= 0 && grid[i][j-1] == -1){
                return dp[i][j] = solve(i+1, j-1, grid);
            } else {
                return -1;
            }
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        //  1  1  1 -1 -1
        //  1  1  1 -1 -1
        // -1 -1 -1  1  1
        //  1  1  1  1 -1
        // -1 -1 -1 -1 -1 
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        vector<int> res(m, -1);
        for(int j = 0;j<m;j++){
            int ans = solve(0, j, grid);
            res[j] = ans;
        }
        return res;
    }
};