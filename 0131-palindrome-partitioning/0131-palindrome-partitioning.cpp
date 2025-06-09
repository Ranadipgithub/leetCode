class Solution {
public:
    void solve(string &s, int i, vector<string> &currPart,vector<vector<bool>>&t, vector<vector<string>> &res){
        if(i == s.size()){
            res.push_back(currPart);
            return;
        }
        for(int j = i;j<s.size();j++){
            if(t[i][j]){
                currPart.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currPart, t, res);
                currPart.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>>t(n, vector<bool>(n, false));
        for(int l = 1;l<=n;l++){
            for(int i = 0;i+l-1<n;i++){
                int j = i+l-1;
                if(i == j) t[i][j] = true;
                else if(i+1 == j) t[i][j] = s[i] == s[j];
                else t[i][j] = s[i] == s[j] && t[i+1][j-1];
            }
        }
        vector<string> currPart;
        vector<vector<string>> res;
        solve(s, 0, currPart, t, res);
        return res;
    }
};