class Solution {
private:
    int numSubarraysLessThanSum(vector<int>& nums, int goal){
        int l = 0, r = 0, count = 0, sum = 0;
        if(goal<0) return 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal && l<=r){
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysLessThanSum(nums, goal) - numSubarraysLessThanSum(nums, goal - 1);
    }
};