class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // for all odd check
        int minOdd = INT_MAX;
        bool fg1 = true;
        for(int i = 0;i<n;i++){
            if(nums[i]%2 == 1){
                minOdd = min(minOdd, nums[i]);
            } else {
                if(minOdd == INT_MAX){
                    fg1 = false;
                    break;
                }
            }
        }
        // for all even
        bool fg2 = true;
        minOdd = INT_MAX;
        for(int i = 0;i<n;i++){
            if(nums[i]%2 == 1){
                if(minOdd == INT_MAX) fg2 = false;
                minOdd = min(minOdd, nums[i]);
            }
        }
        return fg1 | fg2;
    }
};