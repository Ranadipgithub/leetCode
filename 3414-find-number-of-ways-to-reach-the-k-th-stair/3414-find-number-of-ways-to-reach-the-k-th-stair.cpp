class Solution {
public:
    unordered_map<string, int>mpp;
    int solve(int i, int k, bool canComeBack, int jump){
        if(i > k+1 || i<0) return 0;
        string key = to_string(i) + "_" + to_string(canComeBack) + "_" + to_string(jump);
        if (mpp.find(key) != mpp.end()) return mpp[key];
        int ways = 0;
        if(i == k){
            ways += 1;
        }
        if(canComeBack && i> 0) ways += solve(i-1, k, false, jump);
        ways += solve(i+(1 << jump), k, true, jump+1);
        return mpp[key] = ways;
    }
    int waysToReachStair(int k) {
        mpp.clear();
        return solve(1, k, true, 0);
    }
};