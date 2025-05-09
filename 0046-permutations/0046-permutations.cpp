class Solution {
public:
    void solve(vector<int>&nums, int start, vector<vector<int>> &v){
        if(start == nums.size() - 1){
            v.push_back(nums);
            return;
        }
        set<int> st;
        for(int i = start;i<nums.size();i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
                swap(nums[start], nums[i]);
                solve(nums, start+1, v);
                swap(nums[start], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        int start = 0;
        solve(nums, start, v);
        return v;
    }
};