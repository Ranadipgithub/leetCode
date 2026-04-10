class Solution {
public:
    vector<vector<int>>directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        q.push({0, 0, k, 0});
        vector<vector<int>> visited(n, vector<int>(m, -1));
        visited[0][0] = k;
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();

            int i = temp[0], j = temp[1], rem = temp[2], steps = temp[3];
            if(i == n-1 && j == m-1) return steps;
            for(auto &dir: directions){
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
                int new_rem = rem - grid[newi][newj];
                if(new_rem >= 0 && visited[newi][newj] < new_rem){
                    visited[newi][newj] = new_rem;
                    q.push({newi, newj, new_rem, steps+1});
                }
            }
        }
        return -1;
    }
};