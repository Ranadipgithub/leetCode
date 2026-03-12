class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(); 
        int start = 0, end = 0;
        int maxi = INT_MIN, sum = 0;
        for(int i = 0;i<n;i++){
            if(sum < 0){
                sum = nums[i];
                start = i;
            } else {
                sum += nums[i];
            }
            if(sum > maxi){
                maxi = sum;
                end = i;
            }
        }
        int mini = INT_MAX;
        sum = 0;
        for(int i = 0;i<n;i++){
            if(sum > 0){
                sum = nums[i];
                start = i;
            } else {
                sum += nums[i];
            }
            if(sum < mini){
                mini = sum;
                end = i;
            }
        }
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(maxi < 0) return maxi;
        return max(maxi, total-mini);
    }
};