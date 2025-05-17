class Solution {
public:
    queue<pair<int, int>> q;
    vector<vector<int>> direction{{-1, 0}, {1, 0},{0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != 1){
            return;
        }
        grid[i][j] = -1;
        q.push({i, j});
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        bool found = false;
        for(int i = 0; i < n; i++){
            if (found) break; 
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    found = true; 
                    break;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int> curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;
                for(auto &dir: direction){
                    int newi = i + dir[0];
                    int newj = j + dir[1];

                    if(newi >= 0 && newi < n && newj >= 0 && newj < m){
                        if(grid[newi][newj] == 1){
                            return cnt;
                        }
                        if(grid[newi][newj] == 0){
                            q.push({newi, newj});
                            grid[newi][newj] = -1;
                        }
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
};
