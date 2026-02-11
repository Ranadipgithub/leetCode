class NumArray {
public:
    vector<int> segTree;
    int n;
    void buildSegTree(vector<int>&nums, int i, int l, int r){
        if(l == r){
            segTree[i] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        buildSegTree(nums,2*i+1, l, mid);
        buildSegTree(nums, 2*i+2, mid+1, r);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    void updateSegTree(int idx, int val, int i, int l, int r){
        if(l == r){
            segTree[i] = val;
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid){
            updateSegTree(idx, val, 2*i+1, l, mid);
        } else {
            updateSegTree(idx, val, 2*i+2, mid+1, r);
        }
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int rangeQuery(int left, int right, int i, int l, int r){
        if(r < left || l > right){
            return 0;
        } else if(l >= left && r <= right){
            return segTree[i];
        } else {
            int mid = (l+r)/2;
            int res1 = rangeQuery(left, right, 2*i+1, l, mid);
            int res2 = rangeQuery(left, right, 2*i+2, mid+1, r);

            return res1+res2;
        }
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n, 0);

        buildSegTree(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        updateSegTree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return rangeQuery(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */