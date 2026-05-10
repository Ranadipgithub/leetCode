class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> mpp;
        int maxi = n;
        for(int i = 0;i<n;i++){
            maxi = max(maxi, i + (int)nums[i].size());
        }
        mpp.resize(maxi);
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<nums[i].size();j++){
                mpp[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> res;
        for(auto &it: mpp){
            for(int &x: it) res.push_back(x);
        }
        return res;
    }
};