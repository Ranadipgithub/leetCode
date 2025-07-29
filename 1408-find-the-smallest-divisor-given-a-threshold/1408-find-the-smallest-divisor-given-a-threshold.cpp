class Solution {
private:
    int sum(vector<int>& nums, int divisor){
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] % divisor == 0) sum += nums[i]/divisor;
            else sum += 1+nums[i]/divisor;
            // sum += (nums[i]+divisor-1)/divisor;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            maxi = max(nums[i],maxi);
        }
        int low = 1, high = maxi;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(sum(nums, mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};