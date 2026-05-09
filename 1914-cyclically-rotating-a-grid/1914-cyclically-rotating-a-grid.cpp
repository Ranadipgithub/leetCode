class Solution {
public:
    vector<int> getBoundary(vector<vector<int>>& grid, int idx){
        int n = grid.size(), m = grid[0].size();
        vector<int> res;
        for(int j = idx;j<m-idx;j++){
            res.push_back(grid[idx][j]);
        }
        for(int i = 1+idx;i<n-idx;i++){
            res.push_back(grid[i][m-1-idx]);
        }
        for(int j = m-2-idx;j>=idx;j--){
            res.push_back(grid[n-1-idx][j]);
        }
        for(int i = n-2-idx;i>=1+idx;i--){
            res.push_back(grid[i][idx]);
        }
        return res;
    }
    void updateBoundary(vector<vector<int>>& grid, int idx, vector<int>& temp){
        int n = grid.size(), m = grid[0].size();
        int k = 0;
        for(int j = idx;j< m-idx;j++){
            grid[idx][j] = temp[k++];
        }
        for(int i = idx+1;i<n-idx;i++){
            grid[i][m-1-idx] = temp[k++];
        }
        for(int j = m-2-idx;j>=idx;j--){
            grid[n-1-idx][j] = temp[k++];
        }
        for(int i = n-2-idx;i>=idx+1;i--){
            grid[i][idx] = temp[k++];
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i<min(m, n)/2;i++){
            vector<int> temp = getBoundary(grid, i);
            // 1 2 3 4 5
            // 3 4 5 1 2
            // 5 4 3 2 1
            int shift = k % (temp.size());
            reverse(temp.begin(), temp.begin() + shift);
            reverse(temp.begin() + shift, temp.end());
            reverse(temp.begin(), temp.end());
            updateBoundary(grid, i, temp);
        }
        return grid;
    }
};