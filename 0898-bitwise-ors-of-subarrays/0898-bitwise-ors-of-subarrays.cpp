class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> prev, res;
        for(int i = 0;i<n;i++){
            unordered_set<int> curr;
            for(auto &val: prev){
                int newVal = val | arr[i];
                curr.insert(newVal);
                res.insert(newVal);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev = curr;
        }
        return res.size();
    }
};