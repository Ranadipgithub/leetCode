class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for(auto &trip: trips){
            int start = trip[1], end = trip[2];
            if(trip[0] > capacity) return false;
            diff[start] += trip[0];
            diff[end] -= trip[0];
        }
        int cnt = 0;
        for(int i = 0;i<diff.size();i++){
            cnt += diff[i];
            if(cnt > capacity) return false;
        }
        return true;
    }
};