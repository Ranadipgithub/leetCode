class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int x = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(i != nums[i]){
                x &= i;
            }
        }
        return x == INT_MAX ? 0 : x;
    }
};