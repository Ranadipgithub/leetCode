class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> indices;
        for(int i = 0;i<n;i++){
            if(nums[i] == key){
                indices.push_back(i);
            }
        }
        vector<int> res;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<indices.size();j++){
                if(abs(i - indices[j]) <= k){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};