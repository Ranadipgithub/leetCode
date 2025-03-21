class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        bool fg = true;
        for(int i = 0;i<n;i++){
            if(nums[i] > 0) fg = false;
        }
        if(fg){
            return *max_element(nums.begin(),nums.end());
        }
        set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        int sum = 0;
        for(auto it: st){
            if(it > 0) sum += it;
        }
        return sum;
    }
};