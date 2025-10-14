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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxarea = 0;
        vector<int> arr(m, 0);
        for(int i = 0;i<n;i++){
            vector<char> temp = matrix[i];
            for(int i = 0;i<m;i++){
                if(temp[i] == '0') arr[i] = 0;
                else arr[i] = arr[i] + (temp[i]-'0');
            }
            int area = largestRectangleArea(arr);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};