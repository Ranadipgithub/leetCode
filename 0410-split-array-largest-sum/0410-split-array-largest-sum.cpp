class Solution {
public:
    bool isPossible(vector<int>&nums, int sum, int k){
        int n = nums.size();
        int sum1 = nums[0], cnt = 1;
        for(int i = 1;i<n;i++){
            if(sum1 + nums[i] > sum){
                sum1 = nums[i];
                cnt++;
            } else{
                sum1 += nums[i];
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums, mid, k)){
                ans = min(ans, mid);
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
};