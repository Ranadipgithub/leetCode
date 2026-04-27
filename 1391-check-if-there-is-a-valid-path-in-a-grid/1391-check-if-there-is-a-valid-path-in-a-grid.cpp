class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool solve(int i, int j, unordered_map<int, unordered_map<int, vector<int>>> &adj, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(i == n-1 && j == m-1) return true;
        visited[i][j] = true;
        for(int d = 0; d < 4; d++){
            int newi = i + directions[d][0];
            int newj = j + directions[d][1];

            if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
            if(visited[newi][newj]) continue;

            int curr = grid[i][j];
            int next = grid[newi][newj];

            if(adj[curr].count(d)){
                auto &vec = adj[curr][d];
                if(find(vec.begin(), vec.end(), next) != vec.end()){
                    if(solve(newi, newj, adj, grid, visited)) return true;
                }
            }
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        unordered_map<int, unordered_map<int, vector<int>>> adj;
        adj[1][1] = {1,4,6}; // left
        adj[1][3] = {1,3,5}; // right
        adj[2][0] = {2,3,4}; // up
        adj[2][2] = {2,5,6}; // down
        adj[3][1] = {1,4,6}; // left
        adj[3][2] = {2,5,6}; // down
        adj[4][2] = {2,5,6}; // down
        adj[4][3] = {1,3,5}; // right
        adj[5][0] = {2,3,4}; // up
        adj[5][1] = {1,4,6}; // left
        adj[6][0] = {2,3,4}; // up
        adj[6][3] = {1,3,5}; // right
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        return solve(0, 0, adj, grid, visited);
    }
};