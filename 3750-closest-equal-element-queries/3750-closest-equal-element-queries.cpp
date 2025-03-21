class Solution {
private:
    int solve(unordered_map<int, vector<int>>& mpp, int el, int idx, int n) {
        vector<int>& indices = mpp[el];
        if (indices.size() <= 1) {
            return -1;
        }
        
        auto it = lower_bound(indices.begin(), indices.end(), idx);
        int pos = it - indices.begin();
        int len = indices.size();
        
        int prev_pos = (pos - 1 + len) % len;
        int next_pos = (pos + 1) % len;
        
        int prev_idx = indices[prev_pos];
        int next_idx = indices[next_pos];
        
        int dist_prev = min(abs(idx - prev_idx), n - abs(idx - prev_idx));
        int dist_next = min(abs(idx - next_idx), n - abs(idx - next_idx));
        
        return min(dist_prev, dist_next);
    }

public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        
        for (int i = 0; i < n; ++i) {
            mpp[nums[i]].push_back(i);
        }
        
        vector<int> result;
        for (int q : queries) {
            int el = nums[q];
            int minDist = solve(mpp, el, q, n);
            result.push_back(minDist);
        }
        return result;
    }
};