class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> direction = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        if(q.empty() || q.size() == n * m) return -1;

        int level = -1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front(); q.pop();

                for(auto &dir: direction){
                    int newx = x + dir[0];
                    int newy = y + dir[1];

                    if(newx < 0 || newx >= n || newy < 0 || newy >= m) continue;

                    if(grid[newx][newy] == 0){
                        grid[newx][newy] = 1;
                        q.push({newx, newy});
                    }
                }
            }
            level++;
        }

        return level;
    }
};
