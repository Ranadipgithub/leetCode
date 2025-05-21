class Solution {
public:
    typedef pair<int, pair<int, int>>P;
    vector<vector<int>> direction{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m = heights[0].size();
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0, {0,0}});
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        res[0][0] = 0;
        while(!pq.empty()){
            auto coord = pq.top().second;
            int diff = pq.top().first;
            pq.pop();
            int x = coord.first;
            int y = coord.second;

            for(auto dir: direction){
                int newx = x + dir[0];
                int newy = y + dir[1];

                if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;
                int absdiff = abs(heights[newx][newy] - heights[x][y]);
                int maxdiff = max(diff, absdiff);

                if(res[newx][newy] > maxdiff){
                    res[newx][newy] = maxdiff;
                    pq.push({maxdiff, {newx, newy}});
                }

            }
        }
        return res[n-1][m-1];
    }
};