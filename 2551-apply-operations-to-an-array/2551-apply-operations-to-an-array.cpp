class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        int idx = 0;
        bool fg = false;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                idx = i;
                fg = true;
                break;
            }
        }
        if(fg){
            for(int i = idx+1;i<n;i++){
                if(nums[i] != 0){
                    swap(nums[i], nums[idx]);
                    idx++;
                }
            }
        }
        return nums;
    }
};