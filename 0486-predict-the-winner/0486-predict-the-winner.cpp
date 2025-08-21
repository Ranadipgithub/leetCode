class Solution {
public:
    bool solve(vector<int>&nums, int i, int j, int p1, int p2, int p1turn){
        if(i > j){
            if(p1 >= p2) return true;
            else return false;
        }
        if(p1turn){
            return solve(nums, i+1, j, p1+nums[i], p2, 0) || solve(nums, i, j-1, p1+nums[j], p2, 0);
        } else{
            return solve(nums, i+1, j, p1, p2+nums[i], 1) && solve(nums, i, j-1, p1, p2+nums[j], 1);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n-1, 0, 0, 1);
    }
};