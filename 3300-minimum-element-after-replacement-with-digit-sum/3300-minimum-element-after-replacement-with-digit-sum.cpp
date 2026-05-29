class Solution {
public:
    int cal(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            int sum = cal(nums[i]);
            mini = min(mini, sum);
        }
        return mini;
    }
};