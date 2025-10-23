class Solution {
public:
    vector<int> dp;
    int solve(int i, int n){
        if(i == n){
            return 1;
        }
        if(i>n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = solve(i+1, n) + solve(i+2, n);
    }
    int climbStairs(int n) {
        dp.resize(n, -1);
        return solve(0, n);
    }
};