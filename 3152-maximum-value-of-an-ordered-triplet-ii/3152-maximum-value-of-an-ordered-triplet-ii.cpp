class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        // vector<int> pre(n);
        // vector<int> post(n);
        // int maxi = INT_MIN;
        // int idx = 0;
        // for(int i = 0;i<n;i++){
        //     if(nums[i] > maxi){
        //         maxi = nums[i];
        //     }
        //     pre[idx++] = maxi;
        // }
        // idx = n-1;
        // maxi = INT_MIN;
        // for(int i = n-1;i>=0;i--){
        //     if(nums[i] > maxi){
        //         maxi = nums[i];
        //     }
        //     post[idx--] =  maxi;
        // }
        // long long ans = -1;
        // for(int i = 1;i<n-1;i++){
        //     long long res = (long long)(pre[i-1] - nums[i]) * post[i+1];
        //     if(res < 0) res = 0;
        //     ans = max(res, ans);
        // }

        int imax = 0, dmax = 0;
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans, (long long)dmax*nums[i]);
            dmax = max(dmax, imax - nums[i]);
            imax = max(imax, nums[i]);
            
            
            if(ans < 0) ans = 0;
        }
        return ans;
    }
};