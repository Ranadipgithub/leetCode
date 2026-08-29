class Solution {
public:
    vector<int> result;
    int dp[61][1<<16];
    void solve(int idx, int mask, int n, vector<int>&temp, vector<int>&masks){
        if(idx >= masks.size()) {
            if(mask == ((1<<n) - 1)){
                if(result.empty() || result.size() > temp.size()){
                    result = temp;
                }
            }
            return;
        }
        if(dp[idx][mask] != -1 && temp.size() >= dp[idx][mask]) return;
        dp[idx][mask] = temp.size();
        solve(idx+1, mask, n, temp, masks);
        temp.push_back(idx);
        solve(idx+1, (mask | masks[idx]), n, temp, masks);
        temp.pop_back();
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = people.size();
        memset(dp, -1, sizeof(dp));
        unordered_map<string, int> mpp;
        for(int i = 0;i<n;i++){
            mpp[req_skills[i]] = i;
        }
        vector<int> masks;
        for(auto it: people){
            int mask = 0;
            for(string &s: it){
                int idx = mpp[s];
                mask |= (1 << idx);
            }
            masks.push_back(mask);
        }
        vector<int> temp;
        solve(0, 0, n, temp, masks);
        return result;
    }
};