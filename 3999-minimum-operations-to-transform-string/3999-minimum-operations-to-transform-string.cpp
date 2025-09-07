class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        sort(s.begin(), s.end());
        set<char> st;
        for(char ch: s){
            st.insert(ch);
        }
        int maxi = 0;
        for(char ch: st){
            int ops = ch == 'a'? 0: 'z'-ch+1;
            maxi = max(maxi, ops);
        }
        return maxi;
    }
};