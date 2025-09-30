class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp = nums;
        for(int j = 0;j<n;j++){
            for(int i = 0;i<temp.size()-1;i++){
                temp[i] = (temp[i]+temp[i+1])%10;
            }
            temp.pop_back();
        }
        return temp[0];
    }
};