class Solution {
public:
    int n, m;
    int dp[50][50][50][50]; 
    vector<vector<int>> directions{{0, 1}, {1, 0}};

    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1) return false;
        return true;
    }

    int solve(int i1, int j1, int i2, int j2, vector<vector<int>>& grid){
        if(!isValid(i1, j1, grid) || !isValid(i2, j2, grid)) return -1e9;
        if(i1 == n-1 && j1 == m-1) return grid[i1][j1];

        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];

        int cherries = 0;
        if(i1 == i2 && j1 == j2){
            cherries += grid[i1][j1]; 
        } else {
            cherries += grid[i1][j1] + grid[i2][j2]; 
        }

        int maxNext = -1e9;
        for(auto &dir1: directions){
            for(auto &dir2: directions){
                int newi1 = i1 + dir1[0];
                int newj1 = j1 + dir1[1];
                int newi2 = i2 + dir2[0];
                int newj2 = j2 + dir2[1];
                
                maxNext = max(maxNext, solve(newi1, newj1, newi2, newj2, grid));
            }
        }
        
        if(maxNext == -1e9) return dp[i1][j1][i2][j2] = -1e9;
        
        return dp[i1][j1][i2][j2] = cherries + maxNext;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        memset(dp, -1, sizeof(dp));
        int result = solve(0, 0, 0, 0, grid);
    
        return max(0, result);
    }
};