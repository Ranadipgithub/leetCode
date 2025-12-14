class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();

        long long total = accumulate(balance.begin(), balance.end(), 0LL);
        if (total < 0) return -1;

        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (balance[i] < 0) {
                idx = i;
                break;
            }
        }

        if (idx == -1) return 0;

        long long moves = 0;
        long long value = -balance[idx];
        balance[idx] = 0;

        int dist = 1;
        while (value > 0 && dist < n) {
            int left = balance[(idx - dist + n) % n];
            int right = balance[(idx + dist) % n];

            long long take = min(value, (long long)left + right);
            moves += take * dist;
            value -= take;

            dist++;
        }

        return value == 0 ? moves : -1;
    }
};