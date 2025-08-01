class Solution {
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& boxGrid) {
        int n = boxGrid.size();     
        int m = boxGrid[0].size();  
        vector<vector<char>> grid(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        for (int j = 0; j < n; j++) { 
            int fall_pos = m - 1;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == '*') {
                    fall_pos = i - 1;
                } else if (grid[i][j] == '#') {
                    swap(grid[i][j], grid[fall_pos][j]);
                    fall_pos--;
                }
            }
        }
        return grid;
    }
};