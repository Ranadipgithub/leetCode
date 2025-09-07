class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool fg = true;
        int el = nums[0];
        for(int i = 0;i<n;i++){
            if(nums[i] != el) fg = false;
        }
        return fg? 0: 1;
    }
};