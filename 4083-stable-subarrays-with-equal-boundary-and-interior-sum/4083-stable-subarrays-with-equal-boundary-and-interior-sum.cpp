class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> pre(n);
        pre[0] = (long long)capacity[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (long long)capacity[i];
        }
        map<pair<int, long long>, long long> mpp;
        long long cnt = 0; 
        for (int i = n-1; i >= 0; i--) {
            int el = capacity[i];
            cnt += mpp[{el, pre[i] + 2LL * el}];
            if (i + 1 < n) mpp[{capacity[i + 1], pre[i + 1]}]++;
        }
        return cnt;
    }
};