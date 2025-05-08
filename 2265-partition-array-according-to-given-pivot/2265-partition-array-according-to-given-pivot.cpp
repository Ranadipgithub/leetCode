class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);
        int k = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] < pivot){
                res[k++] = nums[i];
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i] == pivot){
                res[k++] = nums[i];
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i] > pivot){
                res[k++] = nums[i];
            }
        }
        return res;
    }
};