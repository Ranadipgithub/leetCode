class Solution {
public:
    void findZ(vector<int>&z, string &s){
        int l = 0, r = 0;
        for(int i = 1;i<s.size();i++){
            if(i < r){
                z[i] = z[i-l];
                if(i + z[i] > r){
                    z[i] = r-i;
                }
            }
            while(i + z[i] < s.size() && s[z[i]] == s[i+z[i]]) z[i]++;
            if(i + z[i] > r){
                l = i;
                r = i + z[i];
            }
        }
    }
    int distinctEchoSubstrings(string text) {
        //abcabcabc
        //000123123 
        int n = text.size();
        unordered_set<string> st;
        for(int i = 0;i<n;i++){
            string t = text.substr(i);
            vector<int> z(t.size(), 0);
            findZ(z, t);
            for(int j = 1;j<z.size();j++){
                if(z[j] >= j) st.insert(t.substr(0, j));
            }
        }
        return st.size();
    }
};