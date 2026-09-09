class Solution {
public:
    int dp[4096][13];
    int solve(int mask, int k, vector<int>&sum){
        if(k == 1) return sum[mask];
        if(dp[mask][k] != -1) return dp[mask][k];
        int ans = INT_MAX;
        for(int submask = mask;submask > 0; submask = (submask-1)&mask){
            int res = max(sum[submask], solve((mask ^ submask), k-1, sum));
            ans = min(ans, res);
        }
        return dp[mask][k] = ans;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        memset(dp, -1, sizeof(dp));
        vector<int> sum;
        for(int num = 0;num<=(1<<n)-1; num++){
            int curr =0;
            for(int i = 0;i<n;i++){
                if((num & (1 << i))){
                    curr += jobs[n-i-1];
                }
            }
            sum.push_back(curr);
        }
        return solve((1 << n) -1, k, sum);
    }
};