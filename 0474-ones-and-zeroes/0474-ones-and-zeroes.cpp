class Solution {
// private:
//     int solve(vector<string>&strs, int m, int n, int s){
//         if(s == 0){
//             return 0;
//         }

//         int ones = count(strs[s-1].begin(), strs[s-1].end(), '1');
//         int zeros = count(strs[s-1].begin(), strs[s-1].end(), '0');
        
//         if (ones > n || zeros > m) {
//             return solve(strs, m, n, s-1);  
//         } 
        
//         return max(1 + solve(strs, m - zeros, n - ones, s-1), solve(strs, m, n, s-1));

//     }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        // int ans = solve(strs, m, n, s);
        // return ans;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = s - 1; i >= 0; i--) {
            int ones = count(strs[i].begin(), strs[i].end(), '1');
            int zeros = strs[i].length() - ones;

            for (int x = m; x >= zeros; x--) {
                for (int y = n; y >= ones; y--) {
                    dp[x][y] = max(dp[x][y], 1 + dp[x - zeros][y - ones]);
                }
            }
        }
        return dp[m][n];
    }
};