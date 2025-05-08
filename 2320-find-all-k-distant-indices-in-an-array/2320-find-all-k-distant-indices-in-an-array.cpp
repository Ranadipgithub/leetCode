class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> mark(n, false);
        for(int i = 0;i<n;i++){
            if(nums[i] == key){
                int left = max(0, i-k);
                int right = min(n-1, i+k);
                for(int k = left;k<=right;k++){
                    mark[k] = true;
                }
            }
        }

        vector<int> res;
        for(int i = 0;i<n;i++){
            if(mark[i]) res.push_back(i);
        }

        return res;

        // vector<int> indices;
        // for(int i = 0;i<n;i++){
        //     if(nums[i] == key){
        //         indices.push_back(i);
        //     }
        // }
        // vector<int> res;
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<indices.size();j++){
        //         if(abs(i - indices[j]) <= k){
        //             res.push_back(i);
        //             break;
        //         }
        //     }
        // }
        // return res;
    }
};