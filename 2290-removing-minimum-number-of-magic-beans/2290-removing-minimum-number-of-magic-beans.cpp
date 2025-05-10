class Solution {
public:
    long long minimumRemoval(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        vector<long long> suffix(n);
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        long long mini = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long left  = (i > 0 ? prefix[i-1] : 0);
            long long right = (i < n-1? suffix[i+1] - 1LL*(n-i-1)*nums[i]: 0);
            mini = min(mini, left + right);
        }
        return mini;
    }
};