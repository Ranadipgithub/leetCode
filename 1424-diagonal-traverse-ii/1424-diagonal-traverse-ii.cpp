class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<nums[i].size();j++){
                mpp[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> res;
        for(auto it: mpp){
            reverse(it.second.begin(), it.second.end());
            for(int &x: it.second) res.push_back(x);
        }
        return res;
    }
};