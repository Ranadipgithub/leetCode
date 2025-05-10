class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sum1 = 0;
        for(int i = 0;i<n;i++){
            sum1 += nums[i];
            int temp = ((i+1)*nums[i] - sum1) - ((n-i-1)*nums[i] - (sum-sum1));
            res.push_back(temp);
        }
        return res;
        // for(int i = 0;i<n;i++){
        //     int sum = 0;
        //     for(int j = 0;j<n;j++){
        //         sum += abs(nums[i]-nums[j]);
        //     }
        //     res.push_back(sum);
        // }
        // return res;
    }
};