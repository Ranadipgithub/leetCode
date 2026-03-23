class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0,1}};
    bool isPossible(int mid, vector<vector<int>>& grid, vector<vector<int>>& time){
        int n = grid.size(), m = grid[0].size();
        if (time[0][0] <= mid) return false; 
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0] = 1;
        
        int min = mid;
        while(!q.empty()){
            int size = q.size();
            min++; 
            
            while(size--){
                auto it=q.front();
                q.pop();

                int i = it.first, j = it.second;
                for(auto &dir: directions){
                    int newi = i + dir[0];
                    int newj = j  + dir[1];

                    if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
                    if(grid[newi][newj] == 2) continue;

                    if(newi == n-1 && newj == m-1){
                        if(time[newi][newj] >= min) return true;
                    } else if(time[newi][newj] <= min){
                        continue;
                    }

                    if(!visited[newi][newj]){
                        visited[newi][newj] = 1;
                        q.push({newi, newj});
                    }
                }
            }
        }
        return false;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, 2e9)); 
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    time[i][j] = 0;
                    visited[i][j] = 1;
                } else if(grid[i][j] == 2){
                    time[i][j] = -1;
                }
            }
        }
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int i = it.first, j= it.second;
            for(auto &dir: directions){
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi < 0 || newi >= n || newj < 0 || newj >= m || time[newi][newj] == -1){
                    continue;
                }

                if(!visited[newi][newj]){
                    time[newi][newj] = 1 + time[i][j];
                    visited[newi][newj] = 1;
                    q.push({newi, newj});
                }
            }
        }

        int low = 0, high = 1e9;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid, grid, time)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};