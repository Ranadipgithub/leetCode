class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ops = 0;
        stack<int> st;
        st.push(0); 

        for (int x : nums) {
            while (st.top() > x) {
                st.pop();
                ++ops;
            }
            if (st.top() < x) {
                st.push(x);
            }
        }
        while (st.top() > 0) {
            st.pop();
            ++ops;
        }
        return ops;
    }
};