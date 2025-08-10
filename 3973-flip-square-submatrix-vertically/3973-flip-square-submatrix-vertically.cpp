class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> temp = grid;
        int i = x, j = x+k-1;
        while(i < j){
            swap(temp[i], temp[j]);
            i++;
            j--;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i < x || i >= x + k || j < y || j >= y + k){
                    temp[i][j] = grid[i][j];
                }
            }
        }
        return temp;
    }
};