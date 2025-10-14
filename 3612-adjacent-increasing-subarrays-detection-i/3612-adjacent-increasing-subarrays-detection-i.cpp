class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1, 1);
        for(int i = 0;i<n;i++){
            int cnt = 1;
            for(int j = i+1;j<n;j++){
                if(nums[j] > nums[j-1]){
                    cnt++;
                } else break;
            }
            dp[i] = cnt;
        }

        for(int i = 0;i<n;i++){
            if(i+k < n && dp[i] >= k && dp[i+k] >= k) return true;
        }
        return false;
    }
};