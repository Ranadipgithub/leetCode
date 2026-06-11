class Solution {
public:
    bool check(vector<int>&nums){
        int count = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i-1] > nums[i]){
                count++;
            }
        }
        if(nums[n-1] > nums[0]){
            count++;
        }
        return count <= 1;
    }
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool fg1 = check(nums);
        vector<int> temp = nums;
        reverse(temp.begin(), temp.end());
        bool fg2 = check(temp);
        
        if(!fg1 && !fg2) return -1;
        
        int mini = INT_MAX;
        
        if(fg1){
            int pivot = -1;
            for(int i = 1; i < n; i++){
                if(nums[i] < nums[i-1]){
                    pivot = i;
                    break;
                }
            }
            if(pivot == -1) return 0;
            
            mini = min(mini, pivot);
            mini = min(mini, n - pivot + 2); 
        }
        
        if (fg2){
            int pivot = -1;
            for(int i = 1; i < n; i++){
                if(temp[i] < temp[i-1]){
                    pivot = i;
                    break;
                }
            }
            
            if(pivot == -1) {
                mini = min(mini, 1);
            } else { 
                mini = min(mini, 1 + pivot);
                mini = min(mini, n - pivot + 1); 
            }
        }
        return mini;
    }
};