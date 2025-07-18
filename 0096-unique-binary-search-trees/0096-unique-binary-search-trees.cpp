class Solution {
public: 
    int dp[20];
    int solve(int n){
        if(n == 0 || n == 1) return 1;
        int cnt = 0;
        if(dp[n] != -1) return dp[n];
        for(int i = 1;i<=n;i++){
            int numsLeft = i-1;
            int numsRight = n-i;
            cnt += solve(numsLeft) * solve(numsRight);
        }
        return dp[n] = cnt;
    }

    int findCatalan(int n) {
    
    // Base case
        if (n <= 1)
            return 1;

        // catalan(n) is sum of
        // catalan(i)*catalan(n-i-1)
        int res = 0;
        for (int i = 0; i < n; i++)
            res += findCatalan(i) * findCatalan(n - i - 1);

        return res;
    }

    int numTrees(int n) {
        // memset(dp, -1, sizeof(dp));
        return findCatalan(n);
    }
};