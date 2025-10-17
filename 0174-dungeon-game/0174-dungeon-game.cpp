class Solution {
public:
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        if(dp[i][j] != -1) return dp[i][j];

        if(i >= n || j >= m) return 1e9;
        if(i == n-1 && j == m-1){
            if(matrix[i][j] > 0){
                return 1;
            }
            return abs(matrix[i][j]) + 1;
        }

        int right = solve(i, j+1, matrix);
        int down = solve(i+1, j, matrix);

        int res = min(right, down) - matrix[i][j];
        return dp[i][j] = res > 0? res: 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, dungeon);
    }
};