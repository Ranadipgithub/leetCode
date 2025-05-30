class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> dp;
    bool solve(vector<int>& stones, unordered_map<int, int>& mpp, int cs, int pj) {
        if (cs == stones.back()) return true;
        if (mpp.find(cs) == mpp.end() || pj <= 0) return false;
        if (dp[cs].count(pj)) return dp[cs][pj];

        return dp[cs][pj] = solve(stones, mpp, cs + pj - 1, pj - 1) ||
                            solve(stones, mpp, cs + pj, pj) ||
                            solve(stones, mpp, cs + pj + 1, pj + 1);
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int, int> mpp;
        if(stones[1] != 1) return false;
        for (int s : stones) {
            mpp[s] = 1;
        }
        return solve(stones, mpp, 1, 1);
    }
};
