class Solution {
public:
    int n, m;
    int dp[10][1001];
    int solve(int prev, int idx, vector<vector<int>>& grid, vector<unordered_map<int,int>> &freq){
        if(idx >= m) return 0;
        if(dp[prev][idx] != -1) return dp[prev][idx];
        long long minOps = 1e18;
        for(int i = 0;i<=9;i++){
            if(i != prev){
                long long ops = (n - freq[idx][i]) + solve(i, idx+1, grid, freq);
                minOps = min(minOps, ops);
            }
        }
        return dp[prev][idx] = minOps;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        // we need to make the grid like this:-
        // a b c d
        // a b c d
        // a b c d
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int mini = INT_MAX;
        vector<unordered_map<int,int>> freq(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                freq[j][grid[i][j]]++;
            }
        }

        for(int i = 0;i<=9;i++){
            int res = (n - freq[0][i]) + solve(i, 1, grid, freq);
            mini = min(mini, res);
        }

        return mini;
    }
};