class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> mpp;
        for(auto &segment: segments){
            mpp[segment[0]] += (long long)segment[2];
            mpp[segment[1]] -= (long long)segment[2];
        }
        long long sum = 0;
        int start = -1;
        vector<vector<long long>> res;
        for(auto &it: mpp){
            if(start == -1){
                start = it.first;
                sum += it.second;
            } else {
                if(sum != 0) res.push_back({start, it.first, sum});
                start = it.first;
                sum += it.second;
            }
        }
        return res;
    }
};