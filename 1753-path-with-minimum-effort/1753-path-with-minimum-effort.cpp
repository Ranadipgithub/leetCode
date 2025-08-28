class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty()){
            pair<int,int> node = pq.top().second;
            int wt = pq.top().first;
            int x = node.first, y = node.second;
            pq.pop();

            for(auto &dir: directions){
                int newx = x + dir[0];
                int newy = y + dir[1];
                if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;

                int cost = max(wt, abs(heights[newx][newy] - heights[x][y]));
                if(dist[newx][newy] > cost){
                    dist[newx][newy] = cost;
                    pq.push({cost, {newx, newy}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};