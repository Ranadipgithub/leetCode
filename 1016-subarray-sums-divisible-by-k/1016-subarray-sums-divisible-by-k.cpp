class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        mpp[0] = 1;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            int rem = ((pre[i] % k) + k) % k;;
            if(mpp.count(rem)){
                cnt += mpp[rem];
            }
            mpp[rem] += 1;
        }
        return cnt;
    }
};