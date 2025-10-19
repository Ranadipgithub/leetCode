class NumArray {
public:
    vector<int> segTree;
    int n;

    void buildSegTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segTree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegTree(2*i + 1, l, mid, nums);
        buildSegTree(2*i + 2, mid + 1, r, nums);
        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }

    void updateSegTree(int idx, int val, int i, int l, int r) {
        if (l == r) {
            segTree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            updateSegTree(idx, val, 2*i + 1, l, mid);
        else
            updateSegTree(idx, val, 2*i + 2, mid + 1, r);
        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }

    int findRangeSum(int left, int right, int i, int l, int r) {
        if (right < l || left > r)
            return 0;
        if (l >= left && r <= right)
            return segTree[i];
        int mid = l + (r - l) / 2;
        return findRangeSum(left, right, 2*i + 1, l, mid)
             + findRangeSum(left, right, 2*i + 2, mid + 1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4 * n, 0);
        buildSegTree(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        updateSegTree(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right) {
        return findRangeSum(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */