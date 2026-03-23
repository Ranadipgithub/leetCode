class Solution {
public:
    const long long MOD = 1e9+7;
    vector<vector<pair<long long, long long>>> dp;
    pair<long long, long long> solve(int i, int j, int n, int m, vector<vector<int>>&grid){
        if(i == n-1 && j == m-1) return {grid[i][j], grid[i][j]};

        long long maxi = LLONG_MIN, mini = LLONG_MAX;
        if(dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) return dp[i][j];

        if(i+1 < n){
            auto [downMax, downMin] = solve(i+1, j, n, m, grid);
            maxi = max({maxi, 1LL*downMax*grid[i][j], 1LL*downMin*grid[i][j]});
            mini = min({mini, 1LL*downMax*grid[i][j], 1LL*downMin*grid[i][j]});
        }
        
        if(j+1 < m){
            auto [rightMax, rightMin] = solve(i, j+1, n, m, grid);
            maxi = max({maxi, 1LL*rightMax*grid[i][j], 1LL*rightMin*grid[i][j]});
            mini = min({mini, 1LL*rightMax*grid[i][j],1LL* rightMin*grid[i][j]});
        }

        return dp[i][j] = {maxi, mini};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        dp.assign(n+1, vector<pair<long long, long long>>(m+1, {LLONG_MIN, LLONG_MAX}));
        pair<long long, long long> ans = solve(0, 0, n, m, grid);
        long long maxi = max(ans.first, ans.second);
        if(maxi < 0) return -1;
        return maxi%MOD;
    }
};