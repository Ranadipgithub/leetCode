class Solution {
public:
    void solve(string curr, vector<string> &res, int n, char prev, int k, int idx){
        if(n <= 0){
            cout << curr << endl;
            res.push_back(curr);
            return;
        }
        solve(curr+'0', res, n-1, '0', k, idx+1);
        if(prev != '1' && k >= idx){
            solve(curr+'1', res, n-1, '1', k-idx, idx+1);
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        solve("", res, n, '0', k, 0);
        return res;
    }
};