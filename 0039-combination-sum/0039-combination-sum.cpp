class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& temp) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (target < 0) return; 

        for (int i = idx; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], res, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, candidates, target, res, temp);
        return res;
    }
};
