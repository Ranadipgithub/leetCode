class Solution {
public:
    int t[1001];
    int solve(int idx, vector<int>&cost){
        if(idx >= cost.size()) return 0;
        if(t[idx] != -1) return t[idx];
        int left = cost[idx] + solve(idx+1, cost);
        int right = cost[idx] + solve(idx+2, cost);
        return t[idx] = min(left, right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return min(solve(0, cost), solve(1, cost));
    }
};