class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> nums(n*m, 1);
        int k = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                nums[k++] = grid[i][j];
            }
        }
        vector<int>pre(n*m,1);
        for(int i = 1;i<n*m;i++){
            pre[i] = (1LL * pre[i-1] * (nums[i-1] % 12345)) % 12345;
        }
        vector<int>suff(n*m+1, 1);
        for(int i = n*m-2;i>=0;i--){
            suff[i] = (1LL * suff[i+1] * (nums[i+1] % 12345)) % 12345;
        }
        vector<int>res(n*m,0);
        for(int i = 0;i<n*m;i++){
            res[i] = (1LL * pre[i] * suff[i]) % 12345;
        }
        k = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                grid[i][j] = res[k++];
            }
        }
        return grid;
    }
};