class Solution {
public:
    int dp[400][4];
    int day(int idx){
        if(idx == 0) return 1;
        else if(idx == 1) return 7;
        else return 30;
    }

    int solve(vector<int>& days, vector<int>& costs, int idx1, int idx2){
        int n = days.size();
        if(idx1 >= n) return 0;
        if(idx2 >= 3) return INT_MAX;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int idx = lower_bound(days.begin() + idx1, days.end(), days[idx1] + day(idx2)) - days.begin();
        int take = costs[idx2] + solve(days, costs, idx, 0);
        int skip = solve(days, costs, idx1, idx2 + 1);
        return dp[idx1][idx2] = min(take, skip);
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(days, costs, 0, 0);
    }
};