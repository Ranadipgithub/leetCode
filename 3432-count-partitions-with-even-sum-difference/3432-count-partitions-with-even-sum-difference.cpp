class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0, cnt = 0;
        for(int i = 0;i<n-1;i++){
            curr += nums[i];
            int right = sum-curr;
            if((right-curr)%2 == 0) cnt++;
        }
        return cnt;
    }
};