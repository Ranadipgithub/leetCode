class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > 0){
                st.push(nums[i]);
            } else{
                int curr = nums[i];
                while(!st.empty() && st.top() > 0){
                    int sum = curr + st.top();
                    if(sum < 0){
                        st.pop();
                    } else if(sum == 0){
                        st.pop();
                        curr = 0;
                        break;
                    } else{
                        curr = 0;
                        break;
                    }
                }
                if(curr != 0 && st.empty()){
                    ans.push_back(curr);
                }
                // if(st.empty()){
                //     ans.push_back(nums[i]);
                // } else{
                //     int sum = nums[i] + st.top();
                //     if(sum <= 0){
                //         st.pop();
                //     }
                // }
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        for(int i = ans.size() - 1;i>=0;i--){
            res.push_back(ans[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};