class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string res = "";
        for(int i = 0;i<n;i++){
            if(s[i] == '*'){
                if(!res.empty()) res.pop_back();
            } else if(s[i] == '#'){
                res += res;
            } else if(s[i] == '%'){
                reverse(res.begin(), res.end());
            } else {
                res += s[i];
            }
        }
        return res;
    }
};