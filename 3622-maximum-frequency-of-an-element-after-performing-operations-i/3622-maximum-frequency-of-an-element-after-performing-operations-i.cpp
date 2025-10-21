class Solution {
public:
    int findMaxFreq(int el, vector<int>& nums, int k, int numOperations, unordered_map<int, int> &fq){
        auto it = lower_bound(nums.begin(), nums.end(), el-k);
        int idx = it-nums.begin();
        auto it1 = upper_bound(nums.begin(), nums.end(), el+k);
        int idx1 = it1-nums.begin();
        int cnt = idx1-idx-fq[el];
        return min(cnt, numOperations) + fq[el];
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> fq;
        for(int num: nums){
            fq[num]++;
        }
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 1;
        for(int i = 1;i<=high;i++){
            int res = findMaxFreq(i, nums, k, numOperations, fq);
            ans = max(ans, res);
        }
        return ans;
    }
};