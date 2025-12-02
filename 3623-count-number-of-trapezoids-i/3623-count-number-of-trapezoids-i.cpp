class Solution {
public:
    const int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, int> mpp;

        for (auto it : points) {
            int y = it[1];
            mpp[y]++;
        }

        long long cnt = 0;
        long long sum = 0;

        for (auto it : mpp) {
            long long val = 1LL * it.second * (it.second - 1) / 2;
            sum = (sum + val) % MOD;
        }

        long long sum1 = 0;

        for (auto it : mpp) {
            long long val = 1LL * it.second * (it.second - 1) / 2;
            sum1 = (sum1 + val) % MOD;
            cnt = (cnt + ((sum - sum1 + MOD) % MOD) * val) % MOD;
        }

        return cnt % MOD;
    }
};