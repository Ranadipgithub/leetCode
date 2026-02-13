class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int solve(int i, int j, vector<vector<int>>&grid){
        if(i >= n || j >= m) return -1e5;

        if(dp[i][j] != -1) return dp[i][j];
        int maxi = grid[i][j];
        maxi = max(maxi, solve(i+1, j, grid));
        maxi = max(maxi, solve(i, j+1, grid));

        return dp[i][j] = maxi;
    }
    int maxScore(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        memset(dp, -1, sizeof(dp));
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int temp = -1e5;
                if(i+1 < n) temp = max(temp, solve(i+1, j, grid));
                if(j+1 < m) temp = max(temp, solve(i, j+1, grid));

                maxi =  max(maxi, temp - grid[i][j]);
            }
        }
        return maxi;
    }
};