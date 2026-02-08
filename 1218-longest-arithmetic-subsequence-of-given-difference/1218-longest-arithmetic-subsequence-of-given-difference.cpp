class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        vector<int> dp(n+1, 1);
        unordered_map<int, int> mpp;
        int maxi = 1;
        for(int i = 0;i<n;i++){
            if(mpp.count(arr[i] - diff)){
                dp[i] = 1 + dp[mpp[arr[i]-diff]];
            }
            maxi = max(maxi, dp[i]);
            mpp[arr[i]] = i;
        }
        return maxi;
    }
};