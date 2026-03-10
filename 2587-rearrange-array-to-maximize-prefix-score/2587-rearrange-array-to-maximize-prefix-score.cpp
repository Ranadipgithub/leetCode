class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int cnt = 0;
        long long total = 0;
        for(int i = 0;i<n;i++){
            if(total + nums[i] > 0) cnt++;
            total += nums[i];
        }
        return cnt;
    }
};