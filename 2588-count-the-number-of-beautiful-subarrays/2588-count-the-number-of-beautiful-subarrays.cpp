class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // the xor of the elements of the subarray should be 0
        // xorr ^ x = 0;
        // xorr = x;
        int n = nums.size();
        unordered_map<int, long long> mpp;
        mpp[0] = 1;
        long long cnt = 0, xorr = 0;
        for(int i = 0;i<n;i++){
            xorr ^= nums[i];
            cnt += mpp[xorr];
            mpp[xorr]++;
        }
        return cnt;
    }
};