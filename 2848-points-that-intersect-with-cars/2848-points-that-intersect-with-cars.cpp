class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto &num: nums){
            mini = min(mini, num[0]);
            maxi = max(maxi, num[1]);
        }
        vector<int> diff(102, 0);
        for(auto &num: nums){
            diff[num[0]]++;
            diff[num[1]+1]--;
        }
        for(int i = 1;i<101;i++){
            diff[i] += diff[i-1];
        }
        int ans = 0;
        for(int i = mini;i<=maxi;i++){
            if(diff[i] > 0) ans++;
        }
        return ans;
    }
};