class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int currNo = 0;
        char op = '+';
        stack<int> st;
        for (int i = 0; i < n; i++) {
            char currCh = s[i];
            if (isdigit(currCh)) {
                currNo = currNo * 10 + (currCh - '0');
            }

            if ((!isdigit(currCh) && currCh != ' ') || i == n - 1) {
                if (op == '+') {
                    st.push(currNo);
                } else if (op == '-') {
                    st.push(-currNo);
                } else if (op == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * currNo);
                } else if (op == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / currNo);
                }
                op = currCh;
                currNo = 0;
            }
        }

        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
