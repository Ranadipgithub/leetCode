class Solution {
public:
    void solve(string &curr, vector<string> &res, int n, char prev, int k, int idx){
        if(n <= 0){
            res.push_back(curr);
            return;
        }
        curr.push_back('0');
        solve(curr, res, n-1, '0', k, idx+1);
        curr.pop_back();
        if(prev != '1' && k >= idx){
            curr.push_back('1');
            solve(curr, res, n-1, '1', k-idx, idx+1);
            curr.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string temp = "";
        solve(temp, res, n, '0', k, 0);
        return res;
    }
};