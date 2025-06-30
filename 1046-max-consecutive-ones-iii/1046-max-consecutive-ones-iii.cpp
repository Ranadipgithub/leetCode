class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0;
        int i = 0, j = 0;
        int maxLen = 0;
        while (j < n) {
            if (nums[j] == 0) zeros++; 
            
            if (zeros <= k) { 
                maxLen = max(maxLen, j - i + 1); 
                j++;
            } else {  
                while (zeros > k) {
                    if (nums[i] == 0) zeros--;
                    i++;
                }
                j++; 
            }
        }
        return maxLen;
    }
};
