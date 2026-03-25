class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long total = 0;
        for(int i = 0;i<n;i++){
            total += accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            if(sum == total - sum) return true;
        }
        sum = 0;
        for(int j = 0;j<m;j++){
            for(int i  =0;i<n;i++){
                sum += grid[i][j];
            }
            if(sum == total-sum) return true;
        }
        return false;
    }
};