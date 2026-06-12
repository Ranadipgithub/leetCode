class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 0...low-1 low ... mid-1 mid...high  high+1...n-1
        // 000000000 11111111111   01221212012 222222222222
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            } else if(nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};