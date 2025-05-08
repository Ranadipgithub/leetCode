class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> res(n);
        int low = 0, high = n-1;
        int i = 0, j = n-1;
        while(i<n && j>=0){
            if(nums[i] < pivot){
                res[low++] = nums[i];
            } 
            if(nums[j] > pivot){
                res[high--] = nums[j];
            }
            i++;
            j--;
        }
        while(low <= high){
           
            res[low++] = pivot;
        }
        return res;

        // vector<int> res(n);
        // int k = 0;
        // for(int i = 0;i<n;i++){
        //     if(nums[i] < pivot){
        //         res[k++] = nums[i];
        //     }
        // }
        // for(int i = 0;i<n;i++){
        //     if(nums[i] == pivot){
        //         res[k++] = nums[i];
        //     }
        // }
        // for(int i = 0;i<n;i++){
        //     if(nums[i] > pivot){
        //         res[k++] = nums[i];
        //     }
        // }
        // return res;
    }
};