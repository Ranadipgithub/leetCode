class Solution {
private:
    vector<vector<int>> dp; 

    int solve(int n, int currA, int clip, int count) {
        if (currA > n) return INT_MAX;
        if (currA == n) return count;  
        
        if (dp[currA][clip] != -1) return dp[currA][clip];

        int copyAndPaste = INT_MAX, paste = INT_MAX;
        
        if (clip != currA) {
            copyAndPaste = solve(n, currA * 2, currA, count + 2);
        }

        if (clip > 0) {
            paste = solve(n, currA + clip, clip, count + 1);
        }

        return dp[currA][clip] = min(copyAndPaste, paste);
    }

public:
    int minSteps(int n) {
        dp.assign(n + 1, vector<int>(n + 1, -1)); 
        return solve(n, 1, 0, 0); 
    }
};
