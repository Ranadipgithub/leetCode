class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int zeroCount = 0;
        int product = 1;

        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                product *= num;
            }
        }

        if (zeroCount > 1) {
            return res;
        }

        for (int i = 0; i < n; ++i) {
            if (zeroCount == 1) {
                if (nums[i] == 0) {
                    res[i] = product;
                } 
            } else {
                res[i] = product / nums[i];
            }
        }

        return res;
    }
};
