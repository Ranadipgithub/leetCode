class Solution {
public:
    int dp[25][25];
    int solve(int start, int end){
        int cnt = 0;
        if(dp[start][end] != -1) return dp[start][end];
        if(start >= end) return 1;
        for(int i = start;i<=end;i++){
            cnt += solve(start, i-1) * solve(i+1, end);
        }
        return dp[start][end] = cnt;
    }
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            int left = solve(1, i-1);
            int right = solve(i+1, n);
            cnt += left*right;
        }
        return cnt;
    }
};