class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n);
        maxi[0] = nums[0];
        for(int i = 1;i<n;i++){
            maxi[i] = max(maxi[i-1], nums[i]);
        }
        vector<int> pre(n);
        for(int i = 0;i<n;i++){
            pre[i] = gcd(nums[i], maxi[i]);
        }

        sort(pre.begin(), pre.end());
        int i = 0, j = n-1;
        long long res = 0;
        while(i < j){
            res += (long long)gcd(pre[i++], pre[j--]);
        }
        return res;
    }
};