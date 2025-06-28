class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        for(int i = n - 1; i >= n - k; i--) {
            mpp[arr[i]]++;
        }

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(mpp.find(nums[i]) != mpp.end()) {
                res.push_back(nums[i]);
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]); 
                if(res.size() == k) return res;
            }
        }
        return res;
    }
};
