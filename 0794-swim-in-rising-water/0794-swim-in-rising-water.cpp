class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            pair<int,int> node = pq.top().second;
            int wt = pq.top().first;
            int x = node.first, y = node.second;
            pq.pop();

            for(auto &dir: directions){
                int newx = x + dir[0];
                int newy = y + dir[1];
                if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;

                int cost = max(wt, grid[newx][newy]);
                if(dist[newx][newy] > cost){
                    dist[newx][newy] = cost;
                    pq.push({cost, {newx, newy}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};