class Solution {
public:
    int dp[256][9];
    int solve(int idx, int mask, int curr, vector<int>& cookies, int k){
        int n = cookies.size();
        if(k == 0){
            if(mask == (1<<n)-1) return curr;
            return INT_MAX;
        }
        if(idx == cookies.size()){
            if(dp[mask][k-1] != -1) {
                if(dp[mask][k-1] == INT_MAX) return dp[mask][k-1];
                else return max(curr, dp[mask][k-1]);
            }
            int next = solve(0, mask, 0, cookies, k-1);
            dp[mask][k-1] = next;
            if(next == INT_MAX) return INT_MAX;
            return max(curr, next);
        }
        int take = INT_MAX;
        if((mask & (1 << idx)) == 0){
            take = solve(idx+1, mask | (1 << idx), curr+cookies[idx], cookies, k);
        }
        int skip = solve(idx+1, mask, curr, cookies, k);
        return min(take, skip);
    }
    int distributeCookies(vector<int>& cookies, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, cookies, k);
    }
};