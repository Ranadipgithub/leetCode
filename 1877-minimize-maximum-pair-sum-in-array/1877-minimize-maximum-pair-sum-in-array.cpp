class Solution {
public:
    bool isPossible(vector<int>&nums, int mid){
        // 2 3 3 5
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            if(nums[l] + nums[r] > mid){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = nums[0] + nums[1];
        int high = nums[n-2] + nums[n-1];

        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};