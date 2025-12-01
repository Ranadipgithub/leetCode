class Solution {
public:
    bool isPossible(const vector<int>& nums, long long hours, int n){
        long long tot = 1LL * n * hours; 
        for(int num: nums){
            tot -= min((long long)num, hours);
            if(tot <= 0) return true; 
        }
        return tot <= 0;
    }

    long long maxRunTime(int n, vector<int>& nums) {
        long long low = 0;
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isPossible(nums, mid, n)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};