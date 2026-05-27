class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // j - i != nums[j] - nums[i]
        // nums[j] - j != nums[i] - i
        // 4 0 1 0
        int n = nums.size();
        unordered_map<int, int> mpp;
        long long cnt = 0;
        mpp[nums[0]]++;
        for(int i = 1;i<n;i++){
            if(mpp.count(nums[i]-i)){
                cnt += (long long)i-(mpp[nums[i]-i]);
            } else cnt += i;
            mpp[nums[i]-i]++;
        }
        return cnt;
    }
};