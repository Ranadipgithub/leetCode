class Solution {
public:
    int minNumberOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]){
                cnt += max(0, nums[i]-nums[i-1]);
            }
        }
        return cnt + nums[0];
    }
};