class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;
        vector<string> res;
        string temp;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                if(!st.empty()){
                    temp += '(';
                    st.push('(');
                } else{
                    temp = "(";
                    st.push('(');
                }
            } else{
                temp += ')';
                st.pop();

                if(st.empty()){
                    res.push_back(temp);
                    temp = "";
                }
            }
        }
        string ans;
        for(auto str: res){
            // for(auto ch: str) cout << ch;
            // cout << endl;
            for(int i = 1;i<str.size()-1;i++) ans += str[i];
        }
        return ans;
    }
};