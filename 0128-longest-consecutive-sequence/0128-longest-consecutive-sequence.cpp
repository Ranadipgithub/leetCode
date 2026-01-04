class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // 1 2 3 4 100 200
        if(n == 0) return 0;
        int len = 1, maxLen = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] == 1 + nums[i-1]){
                len++;
                maxLen = max(maxLen, len);
            } else if (nums[i] == nums[i-1]) continue;
            else {
                len = 1;
            }
        }
        return maxLen;
    }
};