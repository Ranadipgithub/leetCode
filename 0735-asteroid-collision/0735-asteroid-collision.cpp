class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res;
        for(int i = 0;i<n;i++){
            if(nums[i] > 0){
                st.push(nums[i]);
            } else{
                if(st.empty()){
                    st.push(nums[i]);
                    continue;
                } else{
                    if(st.top() < 0) st.push(nums[i]);
                    else{
                        while(!st.empty() && st.top() < abs(nums[i])){
                            if(st.top() > 0)
                                st.pop();
                            else break;
                        }
                        if(!st.empty()){
                            if(st.top() == abs(nums[i])){
                                st.pop();
                            } else if(st.top() > abs(nums[i])){
                                continue;
                            } else{
                                st.push(nums[i]);
                            }
                        } else{
                            st.push(nums[i]);
                        }
                    }
                }
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};