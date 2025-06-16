class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int diff = nums[j] - nums[i];
                if(diff > 0)
                    maxDiff = max(diff, maxDiff);
            }
        }
        return maxDiff == INT_MIN? -1: maxDiff;
    }
};