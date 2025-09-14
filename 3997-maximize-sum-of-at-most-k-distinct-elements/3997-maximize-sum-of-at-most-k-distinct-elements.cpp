class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n= nums.size();
        set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        vector<int> res;
        for (auto it = st.rbegin(); it != st.rend(); ++it) {
            if(res.size() < k){
                res.push_back(*it);
            }
        }
        return res;
    }
};