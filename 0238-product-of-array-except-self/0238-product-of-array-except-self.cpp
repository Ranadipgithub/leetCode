class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,1);
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1]*nums[i-1];
        }
        vector<int>suff(n+1, 1);
        for(int i = n-2;i>=0;i--){
            suff[i] = suff[i+1]*nums[i+1];
        }
        vector<int>res(n,0);
        for(int i = 0;i<n;i++){
            res[i] = pre[i]*suff[i];
        }
        return res;
        // vector<int> res(n, 0);
        // int zeroCount = 0;
        // int product = 1;

        // for (int num : nums) {
        //     if (num == 0) {
        //         zeroCount++;
        //     } else {
        //         product *= num;
        //     }
        // }

        // if (zeroCount > 1) {
        //     return res;
        // }

        // for (int i = 0; i < n; ++i) {
        //     if (zeroCount == 1) {
        //         if (nums[i] == 0) {
        //             res[i] = product;
        //         } 
        //     } else {
        //         res[i] = product / nums[i];
        //     }
        // }

        // return res;
    }
};
