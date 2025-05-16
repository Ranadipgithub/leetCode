class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        int n = grid1.size();
        int m = grid1[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid2[i][j] != 1){
            return true;
        }
        grid2[i][j] = -1;
        bool isSub = grid1[i][j] == 1;
        isSub &= dfs(grid1, grid2, i+1, j);
        isSub &= dfs(grid1, grid2, i-1, j);
        isSub &= dfs(grid1, grid2, i, j+1);
        isSub &= dfs(grid1, grid2, i, j-1);
        return isSub;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid2[i][j] == 1){
                    if(dfs(grid1, grid2, i, j)) cnt++;
                } 
            }
        }
        return cnt;
    }
};