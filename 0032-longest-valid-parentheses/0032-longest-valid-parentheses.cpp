class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int len = 0, maxLen = 0;
        stack<int> st;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            } else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }

        set<int> idx;

        while(!st.empty()){
            idx.insert(st.top());
            st.pop();
        }

        for(int i = 0;i<n;i++){
            if(idx.find(i) != idx.end()){
                len = 0;
            }
            else {
                len++;
                maxLen = max(maxLen, len);
            }
        }



        // for(int i = 0;i<n;i++){
        //     if(s[i] == '('){
        //         st.push(s[i]);
        //     } else{
        //         if(st.empty()) len = 0;
        //         else {
        //             st.pop();
        //             len += 2;
        //             maxLen = max(maxLen, len);
        //         }
        //     }
        // }
        return maxLen;
    }
};