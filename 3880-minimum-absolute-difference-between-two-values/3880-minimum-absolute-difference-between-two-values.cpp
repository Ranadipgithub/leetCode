class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int one = -1, two = -1;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                one = i;
            }
            if(nums[i] == 2){
                two = i;
            }
            if(one != -1 && two != -1){
                mini = min(mini, abs(two-one));
                if(nums[i] == 1) two = -1;
                else one = -1;
            }
        }
        return mini == INT_MAX? -1 : mini;
    }
};