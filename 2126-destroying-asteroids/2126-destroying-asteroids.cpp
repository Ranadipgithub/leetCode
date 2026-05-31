class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        int n = nums.size();
        multiset<long long> st(nums.begin(), nums.end());
        long long curr = mass;
        
        while(!st.empty()){
            auto it = st.upper_bound(curr);
            if (it == st.begin()) {
                return false;
            } else {
                --it;
                int num = *it;
                st.erase(it);
                curr += num;
            }
        }
        return true;
    }
};