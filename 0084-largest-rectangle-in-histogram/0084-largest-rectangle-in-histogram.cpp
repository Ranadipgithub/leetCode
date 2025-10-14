class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmall(n, -1);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            nextSmall[i] = st.empty()? n: st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int> prevSmall(n, -1);
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            prevSmall[i] = st.empty()? -1: st.top();
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0;i<n;i++){
            int len = nextSmall[i] - prevSmall[i] - 1;
            maxArea = max(maxArea, len*heights[i]);
        }
        return maxArea;
    }
};