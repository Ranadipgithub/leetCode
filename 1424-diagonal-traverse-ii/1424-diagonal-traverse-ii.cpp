class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> mpp(200001);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<nums[i].size();j++){
                mpp[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> res;
        for(auto it: mpp){
            reverse(it.begin(), it.end());
            for(int &x: it) res.push_back(x);
        }
        return res;
    }
};