class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> maxi(m, INT_MIN);

        for (int i = 0; i < m; i++) {
            int maxii = INT_MIN;
            for (int j = 0; j < n; j++) {
                maxii = max(maxii, matrix[j][i]);
            }
            maxi[i] = maxii; 
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = maxi[j];
                }
            }
        }

        return matrix;
    }
};
