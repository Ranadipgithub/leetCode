class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        int maxi = INT_MIN;
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
            pre[idx++] = maxi;
        }
        maxi = INT_MIN;
        idx = n-1;
        for(int i = n-1;i>=0;i--){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
            post[idx--] = maxi;
        }
        long long ans = 0;
        for(int j = 1;j<n-1;j++){
            long long res = (long long)(pre[j-1] - nums[j])*post[j+1];
            ans = max(ans, res);
            if(ans<0) ans = 0;
        }
        return ans;
    }
};