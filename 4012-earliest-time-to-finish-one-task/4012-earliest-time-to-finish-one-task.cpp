class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini = INT_MAX;
        for(auto it: tasks){
            int x = it[0], y = it[1];
            mini = min(mini, x+y);
        }
        return mini;
    }
};