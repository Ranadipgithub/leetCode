class Solution {
public:
    void solve(int idx, int n, int k, vector<vector<int>> &res, vector<int> &temp){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int i = idx;i<=n;i++){
            temp.push_back(i);
            solve(i+1, n, k, res, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(1, n, k, res, temp);
        return res;
    }
};