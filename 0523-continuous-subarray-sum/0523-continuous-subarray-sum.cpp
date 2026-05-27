class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // subarray from i+1 ... j
        // (pre[j] - pre[i]) % k == 0
        // pre[j] %k == pre[i] % k;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int n = nums.size(), sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(mpp.count(sum%k)){
                if(i-mpp[sum%k] >= 2) return true;
            } else mpp[sum%k] = i;
        }
        return false;
    }
};