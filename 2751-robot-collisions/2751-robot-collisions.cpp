class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            mpp[positions[i]] = {healths[i], directions[i], i};
        }
        
        stack<pair<int, int>> st;
        sort(positions.begin(), positions.end());
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++){
            int pos = positions[i];
            int hel = mpp[pos][0];
            char dir = mpp[pos][1];
            int idx = mpp[pos][2];
            
            if(dir == 'L'){
                bool fg = true;
                while(!st.empty()){
                    if(hel > st.top().first){
                        st.pop();
                        hel -= 1;
                    } else if(hel < st.top().first){
                        st.top().first -= 1;
                        fg = false;
                        break;
                    } else {
                        st.pop(); 
                        fg = false;
                        break;
                    }
                }
                if(fg){
                    res[idx] = hel; 
                }
            } else {
                st.push({hel, idx});
            }
        }
        
        while(!st.empty()){
            res[st.top().second] = st.top().first;
            st.pop();
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(res[i] > 0){
                ans.push_back(res[i]);
            }
        }
        
        return ans;
    }
};