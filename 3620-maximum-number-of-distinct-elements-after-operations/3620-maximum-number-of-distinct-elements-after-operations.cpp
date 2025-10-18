class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = INT_MIN, cnt = 0;
        for(int i = 0;i<n;i++){
            int mini = nums[i]-k;
            int maxi = nums[i]+k;
            if(prev < mini){
                prev = mini;
                cnt++;
            } else if(prev < maxi){
                prev++;
                cnt++;
            }
        }
        return cnt;
    }
};