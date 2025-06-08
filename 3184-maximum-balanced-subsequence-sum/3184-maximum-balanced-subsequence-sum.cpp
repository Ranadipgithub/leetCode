class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i);
            long long cur_ans = nums[i];
            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};

// class Solution {
// public:
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         long long n = nums.size();
//         vector<long long> temp(n);
//         for(long long i = 0;i<n;i++){
//             temp[i] = nums[i] - i;
//         }
//         vector<long long> dp(n, 0);
//         for(long long i = 0;i<n;i++){
//             dp[i] = nums[i];
//         }
//         long long maxi = *max_element(nums.begin(), nums.end());
//         if(maxi <= 0) return maxi;
//         for(long long i = 1;i<n;i++){
//             for(long long j = 0;j<i;j++){
//                 if(temp[j] <= temp[i]){
//                     dp[i] = max(dp[i], dp[j]+nums[i]);
//                     maxi = max(maxi, dp[i]);
//                 }
//             }
//         }
//         return maxi;
//     }
// };