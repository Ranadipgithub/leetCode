class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int i = 0, j = 0;
        int maxLen = 1;
        bool fg = false;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0) fg = true;
        }
        if(!fg){
            return n-1;
        }
        while(j<n){
            if(nums[j] == 0) zeros++;
            if(zeros == 1) {
                maxLen = max(maxLen, j-i+1);
                j++;
            } else if(zeros < 1){
                j++;
            }
            else if (zeros > 1){
                while(zeros > 1){
                    if(nums[i] == 0) zeros--;
                    i++;
                }
                j++;
            }
        }
        return maxLen-1;
    }
};