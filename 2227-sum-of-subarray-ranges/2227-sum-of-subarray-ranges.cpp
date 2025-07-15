class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size();
        long long cnt = 0;
        for(long long i = 0;i<n;i++){
            long long mini = nums[i], maxi = nums[i];
            for(long long j = i;j<n;j++){
                if(nums[j] < mini) mini = nums[j];
                if(nums[j] > maxi) maxi = nums[j];
                cnt += (maxi - mini);
            }
        }
        return cnt;
    }
};