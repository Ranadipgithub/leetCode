class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &res){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(target < 0 || idx >= candidates.size()) return;

        temp.push_back(candidates[idx]);
        solve(idx + 1, candidates, target - candidates[idx], temp, res);
        temp.pop_back();

        int nextIdx = idx + 1;
        while(nextIdx < candidates.size() && candidates[nextIdx] == candidates[idx]){
            nextIdx++;
        }

        solve(nextIdx, candidates, target, temp, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, candidates, target, temp, res);
        return res;
    }
};
