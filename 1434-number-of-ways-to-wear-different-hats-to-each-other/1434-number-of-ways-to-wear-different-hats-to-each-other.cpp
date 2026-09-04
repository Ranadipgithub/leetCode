class Solution {
public:
    const int mod = 1e9+7;
    int dp[41][1<<10];
    int solve(int hat, int mask, int n, unordered_map<int, vector<int>> &mpp){
        if(mask == (1 << n) - 1) return 1;
        if(hat > 40) return 0;
        if(dp[hat][mask] != -1) return dp[hat][mask];
        int ways = solve(hat+1, mask, n, mpp);
        for(int &ppl: mpp[hat]){
            if((mask & (1 << ppl)) == 0){
                ways = (ways + solve(hat+1, (mask | (1 << ppl)), n, mpp))%mod;
            }
        }
        return dp[hat][mask] = ways;
    }
    int numberWays(vector<vector<int>>& hats) {
        // you have 10 people and at max 40 hats
        // 3 -> 0
        // 4 -> 0, 1
        // 5 -> 1, 2 
        int n = hats.size();
        memset(dp, -1, sizeof(dp));
        unordered_map<int, vector<int>> mpp;
        for(int i = 0;i<hats.size();i++){
            for(int &hat: hats[i]){
                mpp[hat].push_back(i);
            }
        }
        return solve(1, 0, n, mpp);
    }
};