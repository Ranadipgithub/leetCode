class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pre = grid;

        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                pre[i][j] = pre[i][j-1] + grid[i][j];
            }
        }

        vector<vector<int>> sum = pre;

        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                sum[i][j] = sum[i-1][j] + pre[i][j];
            }
        }

        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(sum[i][j] <= k){
                    cnt++;
                } else break;
            }
        }
        return cnt;
    }
};