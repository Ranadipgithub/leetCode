class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1, 1);
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]){
                dp[i] = 1 + dp[i-1];
            } 
        }

        for(int i = 0;i<n;i++){
            if(i+k < n && dp[i] >= k && dp[i+k] >= k) return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n/2;
        int ans = 1;
         while(low <= high){
             int mid = low + (high - low)/2;
             if(hasIncreasingSubarrays(nums, mid)){
                 ans=mid;
                 low = mid + 1;
             } else{
                 high = mid - 1;
             }
         }
        return ans;
    }
};