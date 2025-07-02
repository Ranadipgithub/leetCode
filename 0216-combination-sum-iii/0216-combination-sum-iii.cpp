class Solution {
public:
    void solve(int idx, int n, int k, vector<int>&temp, vector<vector<int>> &res){
        if(n == 0 && temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(n<0 || idx>9) return;
        temp.push_back(idx);
        solve(idx+1, n-idx, k, temp, res);
        temp.pop_back();
        solve(idx+1, n, k, temp, res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(1, n, k, temp, res);
        return res;
    }
};