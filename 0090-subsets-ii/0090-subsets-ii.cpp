class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int> &temp, vector<vector<int>> &res){
        if(idx == nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(idx+1, nums, temp, res);
        temp.pop_back();
        int index = idx+1;
        while(index < nums.size() && nums[index] == nums[index-1]){
            index++;
        }
        solve(index, nums, temp, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, nums, temp, res);
        // vector<vector<int>> ans(res.begin(), res.end());
        return res;
    }
};