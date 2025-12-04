class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int n = directions.size();
        int cnt = 0;
        for(char ch: directions){
            if(ch == 'R'){
                st.push(ch);
            } else if(ch == 'L'){
                if(!st.empty() && st.top() == 'R'){
                    cnt += 2;
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        cnt += 1;
                        st.pop();
                    }
                    st.push('S');
                } else if(!st.empty() && st.top() == 'S'){
                    cnt += 1;
                }
            } else {
                if (!st.empty() && st.top() == 'R') {
                    cnt += 1;
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        cnt += 1;
                        st.pop();
                    }
                    st.push('S');
                }
                else {
                    st.push('S');
                }
            }
        }
        return cnt;
    }
};