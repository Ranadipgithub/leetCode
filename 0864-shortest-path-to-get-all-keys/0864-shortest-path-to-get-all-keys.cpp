class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int solve(int i, int j, vector<string>& grid, int &keys){
        queue<vector<int>> q;
        q.push({i, j, 0});
        
        vector<vector<vector<int>>> visited(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(64, 0)));
        visited[i][j][0] = 1;
        
        // if keys = 3 => target = 111
        int target = (1 << keys) - 1;
        int moves = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                vector<int> curr = q.front();
                q.pop();

                int ux = curr[0], uy = curr[1], mask = curr[2];
                if(mask == target) return moves;

                for(auto &dir: directions){
                    int vx = ux + dir[0];
                    int vy = uy + dir[1];
                    int newmask = mask;

                    if(vx < 0 || vx >= grid.size() || vy < 0 || vy >= grid[0].size() || grid[vx][vy] == '#') continue;

                    if(isupper(grid[vx][vy])){
                        if((newmask & (1 << (grid[vx][vy] - 'A'))) == 0) continue;
                    }

                    if(islower(grid[vx][vy])){
                        newmask = newmask | (1 << (grid[vx][vy] - 'a'));
                    }

                    if(!visited[vx][vy][newmask]){
                        visited[vx][vy][newmask] = 1;
                        q.push({vx, vy, newmask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
    
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int keys = 0;
        int starti = -1, startj = -1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '@'){
                    starti = i;
                    startj = j;
                }
                if(islower(grid[i][j])) keys++;
            }
        }
        
        return solve(starti, startj, grid, keys);
    }
};