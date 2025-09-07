class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        vector<int> nextGreater(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nextGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        vector<int> prevGreater(n, -1);
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int next = nextGreater[i];
            int prev = prevGreater[i];
            if (next != -1 && prev != -1 && next - prev > 1) {
                cnt++;
            }
        }
        return cnt;
    }
};