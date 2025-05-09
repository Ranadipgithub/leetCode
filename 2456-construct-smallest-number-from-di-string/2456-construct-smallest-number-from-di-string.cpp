class Solution {
public:
    string ans = "";
    bool isMatched(const string &s, const string &pattern) {
        for (int i = 0; i < pattern.length(); i++) {
            if (pattern[i] == 'I' && s[i] >= s[i + 1]) return false;
            if (pattern[i] == 'D' && s[i] <= s[i + 1]) return false;
        }
        return true;
    }
    void perm(string &s, int start, int n, string pattern){
        if(start == n){
            if(isMatched(s, pattern)){
                if(ans.empty() || s<ans){
                    ans = s;
                }
            }
            return;
        }
        for(int i = start;i<=n;i++){
            swap(s[start], s[i]);
            perm(s, start+1, n, pattern);
            swap(s[start], s[i]);
        }
    }
    string smallestNumber(string pattern) {
        int start = 0;
        int n = pattern.size();
        string s;
        for(int i = 1;i<=n+1;i++){
            s += to_string(i);
        }
        // perm(s , start, n, pattern);
        while(!isMatched(s, pattern)){
            next_permutation(begin(s), end(s));
        }
        return s;
    }
};