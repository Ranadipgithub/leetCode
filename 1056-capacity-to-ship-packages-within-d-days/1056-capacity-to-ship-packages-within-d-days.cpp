class Solution {
private:
    int possible(vector<int>& nums, int capacity){
        int days = 1,load = 0;
        for(int i = 0;i<nums.size();i++){
            if(load + nums[i] > capacity){
                days += 1;
                load = nums[i];
            }
            else{
                load += nums[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(possible(weights, mid) <= days){
                high = mid - 1;
                ans = min(ans, mid);
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};