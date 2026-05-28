class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int cnt = 0, sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            cnt += mpp[sum-goal];
            mpp[sum]++;
        }
        return cnt;
    }
};