class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int idx = -1;
        long long total = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            if (idx == -1 && s[i] == '1') {
                idx = i;
            } 
            else if (s[i] == '0' && idx != -1) {
                long long cnt = i - idx;
                total = (total + cnt * (cnt + 1) / 2) % MOD;
                idx = -1;
            }
        }

        if (idx != -1) {
            long long cnt = n - idx;
            total = (total + cnt * (cnt + 1) / 2) % MOD;
        }

        return total;
    }
};