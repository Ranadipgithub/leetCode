class Solution {
public:
    const int MOD = 1e9+7;
    int dp[301][301];
    int solve(vector<int> &nums, int size, int num, int x){
        if(num == 0) return 1;
        if(size == 0 || num<0) return 0;
        if(dp[size][num] != -1) return dp[size][num];
        int take = solve(nums, size-1, num-pow(nums[size-1], x), x);
        int skip = solve(nums, size-1, num, x);
        return dp[size][num] = (take + skip)%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<int> nums;
        memset(dp, -1, sizeof(dp));
        int i = 1;
        while(pow(i, x) <= n){
            nums.push_back(i);
            i++;
        }
        int size = nums.size();
        return solve(nums, size, n, x);
    }
};