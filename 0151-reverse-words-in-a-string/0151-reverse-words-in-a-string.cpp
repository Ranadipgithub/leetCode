class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        int i = 0, j = 0;
        while(j < n){
            while(i < n && s[i] == ' ') i++;   
            if (i >= n) break;
            j = i;
            for(j = i; j < n; j++){          
                if(s[j] == ' '){
                    if (j > i) {              
                        string news = s.substr(i, j - i);
                        st.push(news);
                    }
                    i = j + 1;
                }
            }
            if (i < n) {
                string news = s.substr(i, n - i);
                st.push(news);
                i = n;
            }
            j++;
        }
        string res;
        while(!st.empty()){
            res += st.top();
            res += " ";
            st.pop();
        }
        if(!res.empty()) res.pop_back();
        return res;
    }
};
