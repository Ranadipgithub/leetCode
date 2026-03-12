class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(sum < 0){
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            maxi = max(maxi, sum);
        }
        int mini = INT_MAX;
        sum =0;
        for(int i = 0;i<n;i++){
            if(sum>0){
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            mini = min(mini, sum);
        }
        return max(maxi, abs(mini));
    }
};