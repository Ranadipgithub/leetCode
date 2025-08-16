class Solution {
public:
    unordered_map<string, bool> mpp;
    bool solve(string &s, unordered_set<string> &st, int sidx, int eidx, string res){
        if(eidx >= s.size()){
            if(res == s) return true;
            return false;
        }
        string key = to_string(sidx) + to_string(eidx) + res;
        if(mpp.find(key) != mpp.end()) return mpp[key];
        string news = s.substr(sidx, eidx-sidx+1);
        if(st.find(news) != st.end()){
            return mpp[key] = solve(s, st, eidx+1, eidx+1, res+news) || solve(s, st, sidx, eidx+1, res);
        }
        return mpp[key] = solve(s, st, sidx, eidx+1, res);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(s, st, 0, 0, "");
    }
};