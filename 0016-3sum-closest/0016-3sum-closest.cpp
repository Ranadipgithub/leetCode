class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int mini = INT_MAX;
        int minSum = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<n;i++){
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target){
                    if(target-sum < mini){
                        mini = target-sum;
                        minSum = sum;
                    }
                    // mini = min(mini, target-sum);
                    j++;
                } else if(sum > target){
                    if(sum-target < mini){
                        mini = sum-target;
                        minSum = sum;
                    }
                    // mini = min(mini, sum - target);
                    k--;
                } else{
                    return sum;
                }
            }
        }
        return minSum;
    }
};