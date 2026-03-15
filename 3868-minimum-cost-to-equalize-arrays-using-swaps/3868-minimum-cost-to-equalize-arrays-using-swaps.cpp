class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> mpp, mpp1;
        for(auto it: nums1){
            mpp[it]++;
            mpp1[it]++;
        }
        for(auto it: nums2){
            mpp[it]++;
        }
        // all the elements should occur even no of times
        for(auto it: mpp){
            if(it.second % 2 == 1) return -1;
        }
        int size = mpp.size();
        int cnt = 0;
        for(auto it: mpp1){
            if(it.second >= mpp[it.first]/2){
                cnt += abs(it.second - mpp[it.first]/2);
            }
        }
        return cnt;
    }
};