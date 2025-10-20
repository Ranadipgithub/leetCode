class Solution {
public:
    void updateSegTree(int i, int l, int r, int idx, vector<long long>&segTree){
        if(l == r){
            segTree[i] = 1;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            updateSegTree(2*i+1, l, mid, idx, segTree);
        } else {
            updateSegTree(2*i+2, mid+1, r, idx, segTree);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    long long querySegTree(int start, int end, int i, int l, int r, vector<long long>&segTree){
        if(r < start || l > end){
            return 0;
        }
        if(l >= start && r <= end){
            return segTree[i];
        }
        int mid = l + (r-l)/2;
        long long leftCnt = querySegTree(start, end, 2*i+1, l, mid, segTree);
        long long rightCnt = querySegTree(start, end, 2*i+2, mid+1, r, segTree);
        return leftCnt + rightCnt;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<long long> segTree(4*n,  0);
        unordered_map<int, int> mpp;
        for(int i = 0;i<n;i++){
            mpp[nums2[i]] = i;
        }

        updateSegTree(0, 0, n-1, mpp[nums1[0]], segTree);
        long long total = 0;
        for(int i = 1;i<n-1;i++){
            int idx = mpp[nums1[i]];

            long long leftCommonCnt = querySegTree(0, idx, 0, 0, n-1, segTree);
            long long leftUncommonCnt = i - leftCommonCnt;

            long long rightCnt = (n-1) - idx;
            long long rightCommonCnt = rightCnt - leftUncommonCnt;

            total += leftCommonCnt * rightCommonCnt;
            updateSegTree(0, 0, n-1, idx, segTree);
        }
        return total;
    }
};