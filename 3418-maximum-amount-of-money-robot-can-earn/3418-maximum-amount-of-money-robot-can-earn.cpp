class Solution {
public:
    int n, m;
    int dp[501][501][3];
    int solve(int i, int j, vector<vector<int>>& coins, int p){
        if(i >= n || j >= m) return -1e9;
        if(i == n-1 && j == m-1) {
            if(coins[i][j] < 0 && p > 0) return 0;
            return coins[i][j];
        }
        if(dp[i][j][p] != -1e9) return dp[i][j][p];
        int cnt = 0;
        if(coins[i][j] >= 0){
            cnt += max(coins[i][j] + solve(i, j+1, coins, p), coins[i][j] + solve(i+1, j, coins, p));
        } else {
            int op1 = coins[i][j] + solve(i, j+1, coins, p);
            int op2 = coins[i][j] + solve(i+1, j, coins, p);
            int op3 = -1e9, op4 = -1e9;
            if(p > 0){
                op3 = solve(i+1, j, coins, p-1);
                op4 = solve(i, j+1, coins, p-1);
            }
            cnt += max({op1, op2, op3, op4});
        }
        return dp[i][j][p] = cnt;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        // 0 1 -1
        // 1 -2 3
        // 2 -3 4
        n = coins.size();
        m = coins[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 3; k++) dp[i][j][k] = -1e9;
            }
        }

        return solve(0, 0, coins, 2);
    }
};