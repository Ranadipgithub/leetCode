class Solution {
    int [] dp = new int[46];
    int solve(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int op1 = solve(n-1);
        int op2 = solve(n-2);
        return dp[n] = op1+op2;
    }
    public int climbStairs(int n) {
        Arrays.fill(dp, -1);
        return solve(n);
    }
}