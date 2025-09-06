class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long sum = 0;
        for (auto &query : queries) {
            long long l = query[0], r = query[1];
            long long total = 0;

            for (int k = 1; k <= 32; k++) {
                long long start = max(l, 1LL << (k - 1));
                long long end = min(r, (1LL << k) - 1);
                if (start > end) continue;
                
                long long count = end - start + 1;
                int cnt = (k + 1) / 2;
                total += count * cnt;
            }

            sum += (total + 1) / 2;
        }
        return sum;
    }
};