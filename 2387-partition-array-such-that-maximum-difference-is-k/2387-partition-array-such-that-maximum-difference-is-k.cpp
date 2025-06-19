class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int start = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] - nums[start] > k){
                ans++;
                start = i;
            }
            if(i == n-1) ans++;
        }
        return ans;
    }
};