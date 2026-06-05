class Solution {
public:
    int dp[10][2][2];
    int solve(string &s, vector<int>&indices, int idx, int tight, int lz){
        if(idx == s.size()) return 1;
        int lb = 0, ub = tight == 1? s[idx]-'0' : 9;
        if(dp[idx][tight][lz] != -1) return dp[idx][tight][lz];
        int res = 0;
        for(int dig = lb;dig<=ub;dig++){
            if(lz && dig == 0){
                res += solve(s, indices, idx+1, (tight && dig == ub), (lz && dig == 0));
            } else {
                auto it = lower_bound(indices.begin(), indices.end(), dig);
                int i = it - indices.begin();
                if(i < indices.size() && dig == indices[i]){
                    res += solve(s, indices, idx+1, (tight && dig == ub), (lz && dig == 0));
                } else {
                    continue;
                }
            }
        }
        return dp[idx][tight][lz] = res;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> indices;
        for(string &s: digits){
            indices.push_back(stoi(s));
        }
        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return solve(s, indices, 0, 1, 1) - 1;
    }
};