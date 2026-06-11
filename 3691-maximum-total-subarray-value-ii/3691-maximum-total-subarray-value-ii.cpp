class SegTree {
public:
    vector<int> segTree;
    bool isMini;
    SegTree(vector<int> nums, bool isMini){
        int n = nums.size();
        segTree.resize(4*n);
        this->isMini = isMini;
        buildSegTree(0, 0, n-1, nums);
    }

    void buildSegTree(int idx, int l, int r, vector<int>&nums){
        if(l == r) {
            segTree[idx] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildSegTree(2*idx+1, l, mid, nums);
        buildSegTree(2*idx+2, mid+1, r, nums);
        segTree[idx] = isMini? min(segTree[2*idx+1], segTree[2*idx+2]): max(segTree[2*idx+1], segTree[2*idx+2]);
    }

    int query(int start, int end, int i, int l, int r){
        if(l > end || r < start) return isMini ? INT_MAX : INT_MIN;
        else if(l >= start && r <= end) return segTree[i];
        else {
            int mid = l + (r-l)/2;
            int left = query(start, end, 2*i+1, l, mid);
            int right = query(start, end, 2*i+2, mid+1, r);
            return isMini? min(left, right) : max(left, right);
        }
    }
};
class Solution {
public:
    typedef long long ll;
    int findDiff(int l, int r, int n, SegTree &minST, SegTree &maxST){
        int mini = minST.query(l, r, 0, 0, n-1);
        int maxi = maxST.query(l, r, 0, 0, n-1);
        return maxi-mini;
    }
    
    long long maxTotalValue(vector<int>& nums, int k) {
        // 4 2 5 1
        // 0 2 3 4
        // 0 3 4
        // 0 4
        // 0
        // as we can see all these are in non decreasing order
        // we have to find out top k values among these
        int n = nums.size();
        SegTree minST(nums, true);
        SegTree maxST(nums, false);
        priority_queue<tuple<int, int, ll>> pq;
        for(int i = 0;i<n;i++){
            int diff = findDiff(i, n-1, n, minST, maxST);
            pq.push({diff, i, n-1});
        }
        ll res = 0;
        while(!pq.empty() && k--){
            auto [diff, l, r] = pq.top();
            pq.pop();

            res += diff;
            if (l <= r - 1) {
                int newDiff = findDiff(l, r-1, n, minST, maxST);
                pq.push({newDiff, l, r-1});
            }
        }
        return res;
    }
};