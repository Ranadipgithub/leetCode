class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mpp;
        for(auto it: arr){
            int bits = __builtin_popcount(it);
            mpp[bits].push_back(it);
        }
        vector<int> res;
        for(auto it: mpp){
            vector<int> temp = it.second;
            sort(temp.begin(), temp.end());
            for(auto it1: temp){
                res.push_back(it1);
            }
        }
        return res;
    }
};