class Solution {
public:
    void solve(string &temp, vector<string> &res, int n){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<3;i++){
            char ch = 'a'+i;
            if(temp.back() != ch){
                temp.push_back(ch);
                solve(temp, res, n);
                temp.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        string temp = "a";
        solve(temp, res, n);
        temp = "b";
        solve(temp, res, n);
        temp = "c";
        solve(temp, res, n);
        if(k > res.size()) return "";
        return res[k-1];
    }
};