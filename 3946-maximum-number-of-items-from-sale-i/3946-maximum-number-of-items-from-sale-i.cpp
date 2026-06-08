class Solution {
public:
    int dp[1001][1501][2];
    int solve(int idx, int budget, int isTaken, vector<vector<int>>& items, vector<int>&factors){
        if(idx >= items.size()) return 0;
        if(budget <= 0) return 0;
        if(dp[idx][budget][isTaken] != -1) return dp[idx][budget][isTaken];
        int cnt = isTaken? 1: 1 + factors[idx];
        int take = 0;
        if(budget >= items[idx][1]){
            take = cnt + solve(idx, budget - items[idx][1], true, items, factors);
        }
        int skip = solve(idx+1, budget, false, items, factors);
        return dp[idx][budget][isTaken] = max(take, skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> factors(items.size());
        memset(dp, -1, sizeof(dp));
        for(int i = 0;i<items.size();i++){
            int cnt = 0;
            for(int j = 0;j<items.size();j++){
                if(i != j && items[j][0] % items[i][0] == 0) cnt++;
            }
            factors[i] = cnt;
        }
        return solve(0, budget, false, items, factors);
    }
};