class Solution {
public:
    int dp[1001][1001];
    int solve(int currLen, int clipboard, int target) {
        if (currLen > target) return 1e9; 
        if (currLen == target) return 0; 
        
        if (dp[currLen][clipboard] != -1) 
            return dp[currLen][clipboard];


        int copy = 1e9;
        if (clipboard != currLen)
            copy = 1 + solve(currLen, currLen, target);

        int paste = (clipboard > 0) ? 1 + solve(currLen + clipboard, clipboard, target) : 1e9;

        return dp[currLen][clipboard] = min(copy, paste);
    }

    int minSteps(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, n);
    }
};
