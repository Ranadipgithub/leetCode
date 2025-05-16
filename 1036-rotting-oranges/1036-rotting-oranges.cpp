class Solution {
public:
    typedef pair<int, int>p;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<p>q;
        int freshCount = 0;

        int time = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0;
        int minute = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                p curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;

                for(vector<int> dir: directions){
                    int newi = i+dir[0];
                    int newj = j + dir[1];

                    if(newi>=0 && newi <n && newj >=0 && newj < m && grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        q.push({newi,newj});
                        freshCount--;
                    }
                }
            }
            minute++;
        }
        
        return freshCount == 0? minute-1: -1;
    }
};