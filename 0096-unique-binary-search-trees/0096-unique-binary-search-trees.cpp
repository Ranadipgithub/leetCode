class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; 
        dp[1] = 1; 

        for (int i = 2; i <= n; ++i) {
            int sum = 0;
            for (int j = 1; j <= i; ++j) {
                int numsLeft = j-1;
                int numsRight = i-j;
                sum += dp[numsLeft] * dp[numsRight];
            }
            dp[i] = sum;
        }

        return dp[n];
    }
};
