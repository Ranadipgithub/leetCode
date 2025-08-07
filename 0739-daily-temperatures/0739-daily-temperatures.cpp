class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> res(n, 0);
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && st.top().first <= arr[i]){
                st.pop();
            }
            res[i] = st.empty()? 0: (st.top().second - i);
            st.push({arr[i], i});
        }
        return res;
    }
};