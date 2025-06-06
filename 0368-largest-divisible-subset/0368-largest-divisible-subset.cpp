class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prevIdx(n, -1);
        // Step 1: Build dp and prevIdx
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[j] % nums[i] == 0) || (nums[i] % nums[j] == 0)) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        prevIdx[i] = j;
                    }
                }
            }
        }

        // Step 2: Find index of LIS end
        int maxi = *max_element(dp.begin(), dp.end());
        int maxiIdx = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                maxiIdx = i;
                break;  // pick the first one for lexicographically smallest
            }
        }

        // Step 3: Reconstruct LIS
        vector<int> res;
        int par = maxiIdx;
        while (par != -1) {
            res.push_back(nums[par]);
            par = prevIdx[par];
        }

        reverse(res.begin(), res.end()); // since we built it backwards
        return res;
    }
};