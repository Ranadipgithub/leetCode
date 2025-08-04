class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        bool inserted = false; 

        for(int i = 0; i < n; i++) {
            if (intervals[i][1] < newInterval[0]) {
                // Current interval ends before newInterval starts
                res.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                // Current interval starts after newInterval ends
                if (!inserted) {
                    res.push_back(newInterval);
                    inserted = true;
                }
                res.push_back(intervals[i]);
            } else {
                // Overlapping intervals
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        if (!inserted) {
            res.push_back(newInterval);
        }

        return res;
    }
};