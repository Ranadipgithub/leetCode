class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i+1] > nums[i]){
                sum += nums[i+1];
                maxSum = max(sum, maxSum);
            } else sum = nums[i+1];
        }
        return maxSum;
    }
};