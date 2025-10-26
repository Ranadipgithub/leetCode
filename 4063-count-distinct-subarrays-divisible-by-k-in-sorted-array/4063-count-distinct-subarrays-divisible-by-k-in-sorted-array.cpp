class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        mpp[0].push_back(-1);
        long long cnt = 0, sum = 0;
        for(int i = 0;i<n;i++){
            sum = (sum + nums[i])%k;
            if(mpp.count(sum%k)){
                auto it = lower_bound(mpp[sum%k].begin(), mpp[sum%k].end(), nums[i]);
                if(it == mpp[sum%k].end()) cnt += mpp[sum%k].size();
                else cnt += it-mpp[sum%k].begin();
            }
            mpp[sum].push_back(nums[i]);
        }
        return cnt;
    }
};