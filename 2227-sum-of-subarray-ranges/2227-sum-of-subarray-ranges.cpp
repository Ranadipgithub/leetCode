class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> prevSmall(n);
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            prevSmall[i] = st.empty() ? make_pair(-1, -1) : st.top();
            st.push({arr[i], i});
        }

        st = stack<pair<int, int>>();

        vector<pair<int, int>> nextSmall(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top().first > arr[i]){ 
                st.pop();
            }
            nextSmall[i] = st.empty() ? make_pair(-1, n) : st.top();
            st.push({arr[i], i});
        }

        long long cnt = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++){
            int nextSmallerIndex = nextSmall[i].second;
            int prevSmallerIndex = prevSmall[i].second;
            long long left = i - prevSmallerIndex;
            long long right = nextSmallerIndex - i;
            cnt = (cnt + arr[i] * left* right);
        }

        return cnt;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> prevSmall(n);
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first <= arr[i]){
                st.pop();
            }
            prevSmall[i] = st.empty() ? make_pair(-1, -1) : st.top();
            st.push({arr[i], i});
        }

        st = stack<pair<int, int>>();

        vector<pair<int, int>> nextSmall(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top().first < arr[i]){ 
                st.pop();
            }
            nextSmall[i] = st.empty() ? make_pair(-1, n) : st.top();
            st.push({arr[i], i});
        }

        long long cnt = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++){
            int nextSmallerIndex = nextSmall[i].second;
            int prevSmallerIndex = prevSmall[i].second;
            long long left = i - prevSmallerIndex;
            long long right = nextSmallerIndex - i;
            cnt = (cnt + arr[i] * left* right);
        }

        return cnt;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        return abs(sumSubarrayMins(nums) - sumSubarrayMaxs(nums));
    }
};