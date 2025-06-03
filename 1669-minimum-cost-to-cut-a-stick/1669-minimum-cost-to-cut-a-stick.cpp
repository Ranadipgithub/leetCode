class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&cuts, int left, int right){
        if(right - left < 2) return 0;
        int res = INT_MAX;
        if(dp[left][right] != -1) return dp[left][right];
        for(int i = left+1;i<=right-1;i++){
            int cost = (cuts[right] - cuts[left]) + solve(cuts, left, i) + solve(cuts, i, right);
            res = min(res, cost);
        }
        return dp[left][right] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        dp.assign(m+3, vector<int>(m+3, -1));
        cuts.insert(begin(cuts), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size()-1);
    }
};