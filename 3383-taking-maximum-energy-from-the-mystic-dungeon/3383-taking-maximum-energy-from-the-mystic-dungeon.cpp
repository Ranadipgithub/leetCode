class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& energy, int i, int k) {
        int n = energy.size();
        if (i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = energy[i] + solve(energy, i + k, k);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        dp.resize(n, -1);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp = solve(energy, i, k);
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};