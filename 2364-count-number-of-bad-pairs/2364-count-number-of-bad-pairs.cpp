class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // j - i != nums[j] - nums[i]
        // nums[j] - j != nums[i] - i
        // 4 0 1 0
        int n = nums.size();
        unordered_map<int, int> mpp;
        long long cnt = 0;
        long long total = (long long) n * (n-1)/2;
        for(int i = 0;i<n;i++){
            cnt += (long long)mpp[nums[i]-i];
            mpp[nums[i]-i]++;
        }
        return total - cnt;
    }
};