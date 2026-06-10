class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int i = 0, j = 0;
        vector<vector<int>> res;
        pq.push({nums1[0]+nums2[0], {0, 0}});
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        while(res.size() < k){
            auto it = pq.top();
            pq.pop();

            int sum = it.first;
            int x = it.second.first, y = it.second.second;
            res.push_back({nums1[x], nums2[y]});
            if (y+1 < nums2.size() && !visited.count({x, y+1})) {
                pq.push({nums1[x] + nums2[y+1], {x, y+1}});
                visited.insert({x, y+1});
            }
            if (x+1 < nums1.size() && !visited.count({x+1, y})) {
                pq.push({nums1[x+1] + nums2[y], {x+1, y}});
                visited.insert({x+1, y});
            }
        }
        return res;
    }
};