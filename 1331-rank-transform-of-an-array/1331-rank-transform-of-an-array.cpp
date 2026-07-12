class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mpp;
        for(int i = 0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        vector<int> res(n, 0);
        int cnt = 1;
        for(auto &it: mpp){
            int curr = cnt;
            for(auto &idx: it.second){
                res[idx] = curr;
            }
            cnt++;
        }
        return res;
    }
};