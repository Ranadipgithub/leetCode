class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int sum = 0, cnt = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum == k) cnt++;
            if(mpp.count(sum-k)){
                cnt += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};