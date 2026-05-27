class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        // subarray sum from (i+1...j) = pre[j] - pre[i];
        // now we want this sum to be divisible by k
        // (pre[j] - pre[i]) % k == 0
        // pre[j]%k == pre[i]%k
        unordered_map<int, int> mpp;
        int sum = 0, cnt = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            int rem = (sum%k + k)%k;
            if(rem == 0) cnt++;
            if(mpp.count(rem)) cnt += mpp[rem];
            mpp[rem]++;
        }
        return cnt;
    }
};