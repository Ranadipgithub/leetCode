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

    int noSubarrayLessThanKOdd(vector<int> &nums, int k){
        int i = 0, j = 0, oddCnt = 0, cnt = 0;
        int n = nums.size();
        while(j<n){
            if(nums[j]%2 == 1) oddCnt++;
            while(oddCnt > k && i<=j){
                if(nums[i] % 2 == 1) oddCnt--;
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return noSubarrayLessThanKOdd(nums, k) - noSubarrayLessThanKOdd(nums, k - 1);
        // for(int i = 0;i<nums.size();i++){
        //     nums[i] = nums[i]%2;
        // }
        // return numSubarraysWithSum(nums, k);
    }
};