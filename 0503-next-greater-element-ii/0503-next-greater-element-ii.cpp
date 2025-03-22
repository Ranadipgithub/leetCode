class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> st;
        for(int i = 2*n-1; i>= 0;i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n){
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = i+1; j <= i+n-1; j++) {
        //         int idx = j%n;
        //         if (nums[idx] > nums[i]) {
        //             ans[i] = nums[idx];
        //             break;
        //         }
        //     }
        // }
        // return ans;
    }
};
