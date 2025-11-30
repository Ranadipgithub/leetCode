class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int mod = sum%p;
        if(mod == 0) return 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        long long pre = 0;
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            pre = (pre + (long long)nums[i])%p;
            int need = (pre - mod+p)%p;
            if(mpp.count(need)){
                ans = min(ans, i-mpp[need]);
            }
            mpp[pre] = i;
        }
        return (ans == INT_MAX || ans == n)? -1: ans;
    }
};