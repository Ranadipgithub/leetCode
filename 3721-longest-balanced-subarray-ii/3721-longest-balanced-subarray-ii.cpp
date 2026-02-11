class Solution {
public:
    vector<int> segTree;
    vector<int> segMin;
    vector<int> segMax;
    vector<int> lazy;
    void buildSegTree(vector<int>&nums, int i, int l, int r){
        if(l == r){
            segTree[i] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        buildSegTree(nums, 2*i+1, l, mid);
        buildSegTree(nums, 2*i+2, mid+1, r);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]); 
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }
    void updateSegTree(vector<int>&nums, int left, int right, int val, int i, int l, int r){
        if(lazy[i] != 0){
            segTree[i] += (r-l+1)*lazy[i];
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];
            if(l != r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }

        if(r < left || l > right){
            return;
        } else if(l >= left && r<= right){
            segTree[i] += (r-l+1)*val;
            segMin[i] += val;
            segMax[i] += val;
            if(l != r){
                lazy[2*i+1] += val;
                lazy[2*i+2] += val;
            }
            return;
        } else {
            int mid = (l+r)/2;
            updateSegTree(nums, left, right, val, 2*i+1, l, mid);
            updateSegTree(nums, left, right, val, 2*i+2, mid+1, r);

            segTree[i] = segTree[2*i+1] + segTree[2*i+2];
            segMin[i] = min(segMin[2*i+1], segMin[2*i+2]); 
            segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
        }
    }
    int ansQuery(int i, int l, int r){
        if(lazy[i] != 0){
            segTree[i] += (r-l+1)*lazy[i];
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];
            if(l != r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(segMin[i] > 0 || segMax[i] < 0) return -1;
        if(l == r){
            return l;
        }

        int mid = (l+r)/2;
        int leftRes = ansQuery(2*i+1, l, mid);
        if(leftRes != -1) return leftRes;
        return ansQuery(2*i+2, mid+1, r);
    }
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        segTree.resize(4*n, 0);
        lazy.resize(4*n, 0);
        segMin.resize(4*n, 0);
        segMax.resize(4*n, 0);
        vector<int> sum(n, 0);
        buildSegTree(sum, 0, 0, n-1);
        int maxLen = 0;
        unordered_map<int, int> mpp;
        for(int r = 0;r<n;r++){
            int val = nums[r] % 2 == 0? 1: -1;

            int prev = -1;
            if(mpp.count(nums[r])){
                prev = mpp[nums[r]];
            }

            if(prev != -1){
                updateSegTree(sum, 0, prev, -val, 0, 0, n-1);
            }

            // for(int l = 0;l<=r;l++){
            //     sum[l] += val;
            // }

            updateSegTree(sum, 0, r, val, 0, 0, n-1);

            // for(int l = 0;l<=r;l++){
            //     if(sum[l] == 0){
            //         maxLen = max(maxLen, r-l+1);
            //         break;
            //     }
            // }

            int idx = ansQuery(0, 0, n-1);
            if(idx != -1){
                maxLen = max(maxLen, r-idx+1);
            }

            mpp[nums[r]] = r;
        }

        return maxLen;
    }
};