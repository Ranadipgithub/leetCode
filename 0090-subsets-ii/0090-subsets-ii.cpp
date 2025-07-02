class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int> &temp, set<vector<int>> &res){
        if(idx == nums.size()){
            res.insert(temp);
            return;
        }
        solve(idx+1, nums, temp, res);
        temp.push_back(nums[idx]);
        solve(idx+1, nums, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        vector<int> temp;
        solve(0, nums, temp, res);
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};