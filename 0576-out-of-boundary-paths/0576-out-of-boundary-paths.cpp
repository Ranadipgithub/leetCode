class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dp[51][51][51];
    const int MOD = 1e9+7;
    int solve(int i, int j, int m, int n, int moves){
        if(i <0 || i >= m || j < 0 || j >= n) return 1;
        if(moves <= 0) return 0;
        if(dp[i][j][moves] != -1) return dp[i][j][moves];
        long long cnt = 0;
        for(auto &dir: directions){
            int newi = i + dir[0];
            int newj = j + dir[1];
            
            cnt = (cnt + solve(newi, newj, m, n, moves - 1))%MOD;
        }
        return dp[i][j][moves] = cnt;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, m, n, maxMove);
    }
};