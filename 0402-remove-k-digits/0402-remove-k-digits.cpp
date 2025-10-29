class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() > (num[i]-'0') && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res = "";
        while(!st.empty()){
            res += st.top() + '0';
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') idx++;
        res = res.substr(idx);
        return res.empty() ? "0" : res;
    }
};