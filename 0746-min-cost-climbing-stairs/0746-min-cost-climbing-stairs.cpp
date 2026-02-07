class Solution {
public:
    vector<int> dp;
    int solve(int i, int n, vector<int>&cost){
        // if(i == n-1){
        //     return cost[i];
        // }
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int op1 = cost[i] + solve(i+1, n, cost);
        int op2 = cost[i] + solve(i+2, n, cost);
        return dp[i] = min(op1, op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1, -1);
        return min(solve(0, n, cost), solve(1, n, cost));
    }
};