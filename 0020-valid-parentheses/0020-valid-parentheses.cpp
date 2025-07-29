class Solution {
public:
    bool isOpening(char ch){
        if(ch == '(' || ch == '{' || ch == '[') return true;
        return false;
    }
    bool isClose(char ch){
        if(ch == ')' || ch == '}' || ch == ']') return true;
        return false;
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0;i<n;i++){
            if(isOpening(s[i])){
                st.push(s[i]);
            } else{
                if(st.empty()) return false;
                if(s[i] == ')' && st.top() == '('){
                    st.pop();
                } else if(s[i] == '}' && st.top() == '{'){
                    st.pop();
                } else if(s[i] == ']' && st.top() == '['){
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};