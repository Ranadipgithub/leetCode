class Solution {
public:
    void solve(string &s, int start, vector<string> &v){
        if(start == s.size() - 1){
            v.push_back(s);
            return;
        }
        set<char> st;
        for(int i = start; i < s.size(); i++){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
                swap(s[start], s[i]);
                solve(s, start+1, v);
                swap(s[start], s[i]);
            }
        }
    }
    bool isPow2(const string &s){
        int n = stoi(s);
        if(n == 0) return false;
        if(n == 1) return true;
        return (n & (n - 1)) == 0;
    }
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        vector<string> res;
        solve(s, 0, res);
        for(int i = 0; i < (int)res.size(); i++){
            if(res[i].size() == s.size() && res[i][0] != '0' && isPow2(res[i])){
                return true;
            }
        }
        return false;
    }
};
