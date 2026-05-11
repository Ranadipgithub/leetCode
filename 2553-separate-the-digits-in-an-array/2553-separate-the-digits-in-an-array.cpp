class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = n-1;i>=0;i--){
            int num = nums[i];
            while(num > 0){
                res.push_back(num%10);
                num = num/10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};