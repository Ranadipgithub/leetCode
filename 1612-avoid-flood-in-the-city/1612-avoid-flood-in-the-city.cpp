class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> zeros;
        unordered_map<int, int> mpp;
        vector<int> res(n, 1);
        for(int i = 0;i<n;i++){
            if(rains[i] == 0){
                zeros.insert(i);
            } else {
                if(mpp.count(rains[i])){
                    int day = mpp[rains[i]];
                    auto it = zeros.lower_bound(day);
                    if(it == zeros.end()) return {};
                    res[*it] = rains[i];
                    zeros.erase(it);
                }
                mpp[rains[i]] = i;
                res[i] = -1;
            }
        }
        return res;
    }
};