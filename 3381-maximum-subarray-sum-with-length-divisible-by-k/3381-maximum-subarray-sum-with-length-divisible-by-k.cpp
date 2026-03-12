class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n+1, 0);
        for(int i = 1;i<=n;i++){
            pre[i] = pre[i-1] + (long long)nums[i-1];
        }

        long long ans = LLONG_MIN;

        for(int i = 0;i<k;i++){
            long long curr = LLONG_MIN;
            for(int j = i+k;j<=n;j+=k){
                long long sum = pre[j] - pre[j-k];
                if(curr < 0){
                    curr = sum;
                } else {
                    curr += sum;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};