auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> segTree;

    void build(int i, int l, int r, vector<int>& heights) {
        if (l == r) {
            segTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, heights);
        build(2 * i + 2, mid + 1, r, heights);

        if (heights[segTree[2 * i + 1]] >= heights[segTree[2 * i + 2]])
            segTree[i] = segTree[2 * i + 1];
        else
            segTree[i] = segTree[2 * i + 2];
    }

    int query(int ql, int qr, int i, int l, int r, vector<int>& heights) {
        if (l > qr || r < ql) return -1;
        if (l >= ql && r <= qr) return segTree[i];

        int mid = l + (r - l) / 2;
        int leftIdx = query(ql, qr, 2 * i + 1, l, mid, heights);
        int rightIdx = query(ql, qr, 2 * i + 2, mid + 1, r, heights);

        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;
        return (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree.assign(4 * n, 0);
        build(0, 0, n - 1, heights);

        vector<int> result;
        for (auto& q : queries) {
            int a = q[0], b = q[1];
            int low = min(a, b), high = max(a, b);
            int maxi = max(heights[low], heights[high]);

            if (a == b) {
                result.push_back(a);
                continue;
            }
            if (heights[high] > heights[low]) {
                result.push_back(high);
                continue;
            }

            int l = high + 1, r = n - 1, ans = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int idx = query(high + 1, mid, 0, 0, n - 1, heights);
                if (idx != -1 && heights[idx] > maxi) {
                    ans = idx;
                    r = mid - 1;
                } else l = mid + 1;
            }
            result.push_back(ans);
        }
        return result;
    }
};