class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> st;
        vector<int> res(m);
        for(int i = m-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            res[i] = st.empty()? -1: st.top();
            st.push(nums2[i]);
        }
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(nums2[j] == nums1[i]){
                    ans[i] = res[j];
                    break;
                }
            }
        }
        return ans;
    }
};