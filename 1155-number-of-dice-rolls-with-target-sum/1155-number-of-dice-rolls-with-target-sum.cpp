class Solution {
public:
    int dp[31][1001];
    const int mod = 1e9+7;
    int solve(int n, int k, int target){
        if(target < 0) return 0;
        if(n==0 ){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[n][target] != -1) return dp[n][target];
        long long ways = 0;
        for(int num = 1;num<=k;num++){
            ways = (ways + solve(n-1, k, target-num)) % mod; 
        }
        return dp[n][target] = ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        // no are 1,2,3,4,...k
        // total no of dices = n
        // target 
        // (1->k) + (1->k) + ... + (1->k) = target
        // we have to find no of ways
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target);
    }
};