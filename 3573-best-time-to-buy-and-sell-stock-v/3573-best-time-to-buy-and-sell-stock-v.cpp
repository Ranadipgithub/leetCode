class Solution {
public:
    static constexpr long long NEG_INF = LLONG_MIN/2;
    vector<vector<array<long long, 3>>> arr;
    vector<int> prices;

    long long solve(long long i, long long t, long long s, long long n, long long k) {
        if (i == n) {
            if(s == 0) return 0LL;
            return NEG_INF;
        }
        long long &res = arr[i][t][s];
        if (res != LLONG_MIN) 
            return res;
        long long best = solve(i+1, t, s, n, k);

        if (s == 1) best = max(best, solve(i+1, t, 0, n, k) + prices[i]);
        if (s == 2) best = max(best, solve(i+1, t, 0, n, k) - prices[i]);
        if (s == 1) best = max(best, solve(i+1, t, 1, n, k));
        if (s == 0 && t < k) best = max(best, solve(i+1, t+1, 1, n, k) - prices[i]);
        if (s == 2) best = max(best, solve(i+1, t, 2, n, k));
        if (s == 0 && t < k) best = max(best, solve(i+1, t+1, 2, n, k) + prices[i]);
        return res = best;
    }

    long long maximumProfit(vector<int>& p, int k) {
        prices = p;
        long long n = prices.size();
        arr.assign(n + 1, vector<array<long long, 3>>(k + 1, {LLONG_MIN, LLONG_MIN, LLONG_MIN}));
        return solve(0, 0, 0, n, k);
    }
};
