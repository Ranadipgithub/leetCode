class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = sum - x;
        if (target < 0) return -1; 
        if (target == 0) return n;

        unordered_map<long long, int> mpp; 
        long long sum1 = 0;
        int maxi = -1;
        mpp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum1 += nums[i];
            if (mpp.find(sum1 - target) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum1 - target]);
            }
            if (mpp.find(sum1) == mpp.end()) 
                mpp[sum1] = i;
        }

        return maxi == -1 ? -1 : n - maxi;
    }
};