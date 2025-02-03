class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length = 1;
        int maxLength = 1;
        for(int i = 0;i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                length++;
                maxLength = max(length, maxLength);
            }
            else length = 1;
        }
        int length2 = 1, maxLength2 = 1;
        for(int i = 0;i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                length2++;
                maxLength2 = max(length2, maxLength2);
            }
            else length2 = 1;
        }
        return max(maxLength, maxLength2);
    }
};