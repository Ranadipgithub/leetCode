class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            nums[i] = nums[i]%value;
        }
        unordered_map<int, int> mpp;
        for(int num: nums){
            while(num<0){
                num += value;
            }
            mpp[num]++;
        }
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = -1;
        for(int i = 0;i<INT_MAX;i++){
            mpp[i%value]--;
            if(!mpp.count(i%value) || mpp[i%value] < 0) return i;
        }
        return maxi + 1;
    }
};