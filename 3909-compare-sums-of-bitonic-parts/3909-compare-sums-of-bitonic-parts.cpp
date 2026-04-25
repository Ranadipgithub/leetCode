class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int idx = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid > 0 && mid < n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                idx = mid;
                break;
            }
            else if(mid < n-1 && nums[mid] < nums[mid+1]){
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        long long sum1 = accumulate(nums.begin(), nums.begin() + idx + 1, 0LL); 
        long long sum2 = accumulate(nums.begin() + idx, nums.end(), 0LL); 

        if(sum1 > sum2) return 0;
        else if(sum2 > sum1) return 1;
        else return -1;
    }
};