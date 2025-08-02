class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalSum = 0;
        int diagSum = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j || (i+j == n-1)){
                    if(grid[i][j] == 0) return false;
                    diagSum += grid[i][j];
                }
                totalSum += grid[i][j];
            }
        }
        return totalSum == diagSum;
    }
};