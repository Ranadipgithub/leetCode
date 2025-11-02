class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long R_max = 100000LL;
        long long R_min = -100000LL;
        
        long long res = -LLONG_MAX; 

        res = max(res, (long long)nums[0] * nums[1] * R_max);
        res = max(res, (long long)nums[n-1] * nums[n-2] * R_max);
        res = max(res, (long long)nums[0] * nums[n-1] * R_min);

        if (n > 3) {
            res = max(res, (long long)nums[n-1] * nums[n-2] * nums[n-3]);
            res = max(res, (long long)nums[0] * nums[1] * nums[n-1]);
        }

        return res;
    }
};