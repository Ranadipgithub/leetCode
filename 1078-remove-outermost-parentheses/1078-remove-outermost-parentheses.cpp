class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;
        string temp;
        vector<string>res;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                if(!st.empty()){
                    temp += '(';
                    st.push('(');
                } else{
                    temp = "";
                    st.push('(');
                }
            } else{
                st.pop();
                if(st.empty()){
                    res.push_back(temp);
                } else{
                    temp += ')';
                }
            }
        }

        string ans;
        for(int i = 0;i<res.size();i++){
            ans += res[i];
        }
        return ans;
    }
};