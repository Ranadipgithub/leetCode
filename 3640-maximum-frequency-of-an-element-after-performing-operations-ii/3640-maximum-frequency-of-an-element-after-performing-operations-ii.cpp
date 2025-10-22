class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = *max_element(nums.begin(), nums.end())+k;
        map<int, int> mpp;
        unordered_map<int, int> fq;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            fq[nums[i]]++;
            int low = max(0, nums[i]-k);
            int high = min(maxi, nums[i]+k);
            mpp[low]++;
            mpp[high+1]--;
            mpp[nums[i]] += 0;
        }
        
        int res = 1, sum = 0;
        for(auto it: mpp){
            it.second += sum;
            sum = it.second;
            int currFq = fq[it.first];
            int ops = it.second - currFq;
            int maxFq = min(ops, numOperations);
            res = max(res, maxFq+currFq);
        }
        return res;
    }
};