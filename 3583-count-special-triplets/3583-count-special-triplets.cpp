class Solution {
public:
    const long long mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp1;
        for (int num : nums) mpp1[num]++;
        unordered_map<int, int> mpp2;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            mpp1[nums[i]]--;
            if (mpp1.count(nums[i] * 2) && mpp2.count(nums[i] * 2)) {
                cnt = (cnt + (long long)mpp1[nums[i] * 2] * mpp2[nums[i] * 2] % mod)% mod;
            }
            mpp2[nums[i]]++;
        }
        return (int)cnt;
    }
};