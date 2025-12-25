class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0, cnt = 0;
        for(int i = n-1;i>=0;i--){
            if(nums[i]-cnt < 0) break;
            ans += (long long)(nums[i]-cnt);
            cnt++;
            k--;
            if(k<=0) break;
        }
        return ans;
    }
};