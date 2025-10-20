class Solution {
public:
    void createSegTree(int i, int l, int r, vector<int>& segTree, vector<int>& baskets) {
        if (l == r) {
            segTree[i] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        createSegTree(2 * i + 1, l, mid, segTree, baskets);
        createSegTree(2 * i + 2, mid + 1, r, segTree, baskets);
        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    void updateSegTree(int idx, int val, int i, int l, int r, vector<int>& segTree) {
        if (l == r) {
            segTree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            updateSegTree(idx, val, 2 * i + 1, l, mid, segTree);
        else
            updateSegTree(idx, val, 2 * i + 2, mid + 1, r, segTree);

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    int querySegTree(int start, int end, int i, int l, int r, vector<int>& segTree) {
        if (r < start || l > end)
            return 0;
        if (l >= start && r <= end)
            return segTree[i];
        int mid = l + (r - l) / 2;
        int left = querySegTree(start, end, 2 * i + 1, l, mid, segTree);
        int right = querySegTree(start, end, 2 * i + 2, mid + 1, r, segTree);
        return max(left, right);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segTree(4 * n, 0);
        createSegTree(0, 0, n - 1, segTree, baskets);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int el = fruits[i];
            int low = 0, high = n - 1;
            int ans = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int tempAns = querySegTree(0, mid, 0, 0, n - 1, segTree);
                if (tempAns >= el) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (ans != -1) {
                cnt++;
                updateSegTree(ans, 0, 0, 0, n - 1, segTree);
            }
        }
        return n-cnt;
    }
};