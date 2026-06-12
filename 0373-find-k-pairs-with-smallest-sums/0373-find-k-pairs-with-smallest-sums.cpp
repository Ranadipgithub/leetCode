class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({nums1[0]+nums2[0], {0, 0}});
        set<pair<int, int>> st;
        st.insert({0, 0});
        vector<vector<int>> res;
        while(!pq.empty() && k--){
            auto it = pq.top();
            pq.pop();

            int i = it.second.first, j = it.second.second;
            res.push_back({nums1[i], nums2[j]});
            int sum = it.first;
            if(j+1 < m && !st.count({i, j+1})){
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
                st.insert({i, j+1});
            } 
            if(i+1 < n && !st.count({i+1, j})){
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
                st.insert({i+1, j});
            } 
        }
        return res;
    }
};