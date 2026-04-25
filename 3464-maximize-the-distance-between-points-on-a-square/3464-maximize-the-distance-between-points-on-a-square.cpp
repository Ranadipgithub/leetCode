class Solution {
public:
    int ans;
    typedef long long ll;
    void genArray(vector<vector<int>> &points, vector<ll> &res, int side) {
        for (auto &p : points) {
            ll x = p[0], y = p[1], s = side;
            if (y == 0) res.push_back(x);
            else if (x == s) res.push_back(s + y);
            else if (y == s) res.push_back(3 * s - x);
            else res.push_back(4 * s - y);
        }
        sort(res.begin(), res.end());
        int n = res.size();
        for (int i = 0; i < n; i++) res.push_back(res[i] + 4LL * side);
    }

    bool isPossible(int mid, vector<ll> &res, int k, int n, int side) {
        for (int i = 0; i < n; i++) {
            if (res[i] > res[0] + (4LL * side / k)) break; 
            
            int cnt = 1, cur = i;
            for (int j = 1; j < k; j++) {
                auto it = lower_bound(res.begin() + cur, res.begin() + i + n, res[cur] + mid);
                if (it == res.begin() + i + n) { cnt = 0; break; }
                cur = it - res.begin();
                cnt++;
            }
            if (cnt == k && (res[i] + 4LL * side - res[cur]) >= mid) return true;
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> res;
        genArray(points, res, side);
        int n = points.size();
        int low = 1, high = side; 
        ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, res, k, n, side)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};