class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int ans = ~0;
        for(int i = 0;i<n;i++){
            if(nums[i] != temp[i]){
                ans &= nums[i];
            }
        }
        return ans == -1? 0: ans;
    }
};