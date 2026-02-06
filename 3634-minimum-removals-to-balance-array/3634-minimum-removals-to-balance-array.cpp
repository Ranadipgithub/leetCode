class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int len = 0;
        for(int i = 0;i<n;i++){
            long long maxi = (long long)nums[i]*k;
            int idx = upper_bound(nums.begin()+i, nums.end(), maxi) - nums.begin();
            len = max(len, idx-i);
        }
        return n-len;
    }
};