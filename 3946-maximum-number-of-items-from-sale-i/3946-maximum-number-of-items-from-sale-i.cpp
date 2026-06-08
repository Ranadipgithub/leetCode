class Solution {
public:
    int dp[1001][1501];
    int mini;
    int solve(int idx, int budget, vector<vector<int>>& items, vector<int>&factors){
        if(budget <= 0) return 0;
        if(idx >= items.size()) return budget/mini;
        if(dp[idx][budget] != -1) return dp[idx][budget];
        int cnt = 1 + factors[idx];
        int take = 0;
        if(budget >= items[idx][1]){
            take = cnt + solve(idx+1, budget - items[idx][1], items, factors);
        }
        int skip = solve(idx+1, budget, items, factors);
        return dp[idx][budget] = max(take, skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> factors(items.size());
        memset(dp, -1, sizeof(dp));
        mini = INT_MAX;
        for(int i = 0;i<items.size();i++){
            int cnt = 0;
            for(int j = 0;j<items.size();j++){
                if(i != j && items[j][0] % items[i][0] == 0) cnt++;
            }
            factors[i] = cnt;
            mini = min(mini, items[i][1]);
        }
        return solve(0, budget, items, factors);
    }
};