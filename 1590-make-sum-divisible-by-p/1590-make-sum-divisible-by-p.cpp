class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // let's say we want to remove the subarray from i+1...j
        // then the sum of rem should be divisible by p
        // (pre[i] + pre[n-1] - pre[j])%p = 0;
        // pre[i]%p = (pre[j]%p - total%p + p)%p
        int n = nums.size();
        unordered_map<int, int> mpp;
        long long sum = 0;
        int mini = n;
        mpp[0] = -1;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if(total % p == 0) return 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            int curr = (sum % p + p) % p;
            int rem = (sum%p - total%p + p) % p;
            if(mpp.count(rem)){
                mini = min(mini, i - mpp[rem]);
            }
            mpp[curr] = i;
        }
        return mini == nums.size()? -1: mini;
    }
};