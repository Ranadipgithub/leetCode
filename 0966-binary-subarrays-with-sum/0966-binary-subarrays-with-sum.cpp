class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int currSum = 0;
        mpp[0] = 1;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            currSum += nums[i];
            int req = currSum - goal;
            if(mpp.find(req) != mpp.end()){
                cnt += mpp[req];
            }
            mpp[currSum]++;
        }
        return cnt;
    }
};