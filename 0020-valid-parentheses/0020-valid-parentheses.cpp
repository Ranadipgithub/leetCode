class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if((s[i] == ')' || s[i] == '}' || s[i] == ']')){
                if(s[i] == ')' && st.top() == '('){
                    st.pop();
                } 
                else if(s[i] == '}' && st.top() == '{') st.pop();
                
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        return st.empty()? true:false;
    }
};