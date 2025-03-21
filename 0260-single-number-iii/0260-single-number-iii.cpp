class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long xorr = 0;
        for(int i = 0;i<n;i++){
            xorr = xorr ^ nums[i];
        }
        int rightmost = (xorr & xorr-1)^xorr;
        int b1 = 0, b2 = 0;
        for(int i = 0;i<n;i++){
            if(rightmost & nums[i]) b1 ^= nums[i];
            else b2 ^= nums[i];
        }
        vector<int> res;
        res.push_back(b1);
        res.push_back(b2);
        return res;
    }
};