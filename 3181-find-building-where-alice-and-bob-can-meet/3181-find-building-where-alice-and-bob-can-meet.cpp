class Solution {
public:
    vector<int> heights;

    void buildSegTree(int i, int l, int r, vector<int>& segTree) {
        if (l == r) {
            segTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegTree(2 * i + 1, l, mid, segTree);
        buildSegTree(2 * i + 2, mid + 1, r, segTree);

        int leftIdx = segTree[2 * i + 1];
        int rightIdx = segTree[2 * i + 2];

        segTree[i] = (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    int findRMIQ(int ql, int qr, int i, int l, int r, vector<int>& segTree) {
        if (r < ql || l > qr)
            return -1;
        if (l >= ql && r <= qr)
            return segTree[i];
        
        int mid = l + (r - l) / 2;
        int leftIdx = findRMIQ(ql, qr, 2 * i + 1, l, mid, segTree);
        int rightIdx = findRMIQ(ql, qr, 2 * i + 2, mid + 1, r, segTree);

        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;

        return (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights_, vector<vector<int>>& queries) {
        heights = heights_;
        int n = heights.size();

        vector<int> segTree(4 * n);
        if (n > 0) {
            buildSegTree(0, 0, n - 1, segTree);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            if (l > r) swap(l, r);

            if (l == r) {
                ans.push_back(l);
                continue;
            }

            if (heights[r] > heights[l]) {
                ans.push_back(r);
                continue;
            }

            int maxi = max(heights[l], heights[r]);
            
            int low = r + 1, high = n - 1;
            int resIdx = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int idx = findRMIQ(r + 1, mid, 0, 0, n - 1, segTree);
                
                if (idx != -1 && heights[idx] > maxi) {
                    resIdx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans.push_back(resIdx);
        }
        return ans;
    }
};