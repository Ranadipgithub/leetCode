class Solution {
public:
    int minInsertions(string s) {
        // if we encounter a ')' we have to count how many ')' we are getting, accordingly we have count the no of brackets to be inserted, ))) => 3 --- (cnt + 1)/2 + (cnt%2 == 1) - st.size()
        // if in the end of iterations the stack contains some brackets we need 2 closing brackets per opening bracket so cnt += 2*st.size() 
        int n = s.size();
        stack<char> st;
        int total = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '(') st.push(s[i]);
            else {
                int cnt = 0;
                while(i < n && s[i] == ')'){
                    cnt++;
                    if(cnt == 2){
                        if(!st.empty()) st.pop();
                        else total += 1;
                        cnt = 0;
                    }
                    i++;
                }
                // ((()
                if(cnt != 0){
                    if(st.empty()) total += 2;
                    else {
                        total += 1;
                        st.pop();
                    }
                }
                i--;
            }
        }
        total += 2*st.size();
        return total;
    }
};