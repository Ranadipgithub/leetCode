class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int presum = 0, cnt = 0;
        for(int i = 0;i<n;i++){
            presum += nums[i];
            if(presum == k) cnt++;
            if(mpp.find(presum-k) != mpp.end()) cnt+=mpp[presum-k];
            mpp[presum]++;
        }
        return cnt;
    }
};