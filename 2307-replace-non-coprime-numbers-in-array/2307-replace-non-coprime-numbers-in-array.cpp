class Solution {
public:
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i = 0;i<n;i++){
            if(st.empty()) st.push(nums[i]);
            else {
                int gcd_val = gcd(nums[i], st.top());
                while(!st.empty() && gcd_val > 1){ 
                    int lcm_val = lcm(nums[i], st.top());
                    st.pop();
                    nums[i] = lcm_val;
                    if(!st.empty()) gcd_val = gcd(nums[i], st.top());
                }
                st.push(nums[i]);
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};