class Solution {
private:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int currSum = 0;
        mpp[0] = 1;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            currSum += nums[i];
            int req = currSum - goal;
            if(mpp.find(req) != mpp.end()){
                cnt += mpp[req];
            }
            mpp[currSum]++;
        }
        return cnt;
    }

    int numSubarraysLessThanSum(vector<int>& nums, int goal){
        int l = 0, r = 0, count = 0, sum = 0;
        if(goal<0) return 0;
        while(r < nums.size()){
            sum += nums[r]%2;  
            while(sum > goal && l<=r){
                sum -= nums[l]%2;
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // return numSubarraysLessThanSum(nums, k) - numSubarraysLessThanSum(nums, k - 1);
        for(int i = 0;i<nums.size();i++){
            nums[i] = nums[i]%2;
        }
        return numSubarraysWithSum(nums, k);
    }
};