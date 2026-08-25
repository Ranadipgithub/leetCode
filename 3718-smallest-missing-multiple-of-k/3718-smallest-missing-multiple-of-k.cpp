class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        int m = k, i = 1;;
        while(true){
            if(!st.count(m)){
                return m;
            }
            m += k;
        }
    }
};