class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_set<string> st;
        while(j<n){
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                string str = s.substr(i, k);
                st.insert(str);
                i++;
                j++;
            }
        }
        int cnt = pow(2, k);
        if(st.size() == cnt) return true;
        return false;
    }
};