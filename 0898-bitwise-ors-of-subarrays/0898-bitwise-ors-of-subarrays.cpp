class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // as we include more elements it will increase the or value only
        // adding more element will never decrease the or value
        // so there is a monotonocity
        int n = arr.size();
        unordered_set<int> res, prev;
        for(int i = 0;i<n;i++){
            unordered_set<int> curr;
            for(auto &x: prev){
                curr.insert(x|arr[i]);
                res.insert(x|arr[i]);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev = curr;
        }
        return res.size();
    }
};