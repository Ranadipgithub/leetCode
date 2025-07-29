class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmall(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            prevSmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> nextSmall(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            nextSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long cnt = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++){
            long long left = i - prevSmall[i];
            long long right = nextSmall[i] - i;
            cnt = (cnt + arr[i] * left % MOD * right % MOD) % MOD;
        }

        return cnt;
    }
};
