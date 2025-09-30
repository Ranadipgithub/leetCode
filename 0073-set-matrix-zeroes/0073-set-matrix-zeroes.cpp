class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int fgrow = false, fgcol = false;

        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == 0) {
                fgrow = true;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[j][0] == 0) {
                fgcol = true;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (fgrow) {
            for (int i = 0; i < m; i++) {
                matrix[0][i] = 0;
            }
        }

        if (fgcol) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};